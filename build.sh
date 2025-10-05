#!/data/data/com.termux/files/usr/bin/bash
set -e

# Detect Termux vs normal Linux
if [ -d "/data/data/com.termux" ]; then
  echo "[+] Detected Termux environment"
  export OPENSSL_DIR=$PREFIX
  export OPENSSL_LIB_DIR=$PREFIX/lib
  export OPENSSL_INCLUDE_DIR=$PREFIX/include
  export PKG_CONFIG_PATH=$PREFIX/lib/pkgconfig
  export PKG_CONFIG_ALLOW_CROSS=1
else
  echo "[+] Detected standard Linux environment"
  export OPENSSL_DIR=/usr
  export OPENSSL_LIB_DIR=/usr/lib/x86_64-linux-gnu
  export OPENSSL_INCLUDE_DIR=/usr/include/openssl
fi

export CC=gcc
export CXX=g++

cargo build --release -j1 --target-dir ./target
