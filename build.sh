#!/data/data/com.termux/files/usr/bin/bash
set -e

echo "[+] Updating and installing dependencies..."
pkg update -y
pkg install rust clang make pkg-config openssl-tool git -y

# Detect Termux vs. standard Linux
if [ -d "/data/data/com.termux" ]; then
  echo "[+] Detected Termux environment"
  export OPENSSL_DIR=$PREFIX
  export OPENSSL_INCLUDE_DIR=$PREFIX/include
  export OPENSSL_LIB_DIR=$PREFIX/lib
  export PKG_CONFIG_PATH=$PREFIX/lib/pkgconfig
  export PKG_CONFIG_ALLOW_CROSS=1
else
  echo "[+] Detected standard Linux environment"
  export OPENSSL_DIR=/usr
  export OPENSSL_INCLUDE_DIR=/usr/include/openssl
  export OPENSSL_LIB_DIR=/usr/lib/x86_64-linux-gnu
fi

export CC=gcc
export CXX=g++

echo "[+] Building shaipot..."
cargo clean
cargo build --release -j1 --target-dir ./target

if [ -f ./target/release/shaipot ]; then
  echo "[+] Build completed successfully!"
  echo "[+] Binary: ./target/release/shaipot"
