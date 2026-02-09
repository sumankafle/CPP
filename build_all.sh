#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"

usage(){
  cat <<EOF
Usage: $0 [all|console|gui]
  all     build console and Qt GUI
  console build the console app (coffee_machine)
  gui     build the Qt GUI (qt_coffee)
EOF
  exit 1
}

if [[ ${1-"all"} == "-h" || ${1-"all"} == "--help" ]]; then
  usage
fi

TARGET=${1-all}

echo "Build root: $ROOT_DIR"

build_console(){
  echo "Building console app..."
  cd "$ROOT_DIR/coffee_machine"
  if [[ ! -f main.cpp || ! -f IntelligentCoffeeMachine.cpp ]]; then
    echo "Missing console sources in coffee_machine/" >&2
    return 1
  fi
  g++ -std=c++17 main.cpp IntelligentCoffeeMachine.cpp -o intelligent_coffee
  echo "Built: coffee_machine/intelligent_coffee"
}

build_gui(){
  echo "Building Qt GUI..."
  cd "$ROOT_DIR/qt_coffee"
  if ! pkg-config --exists Qt5Widgets Qt5Core; then
    echo "Qt5 (Qt5Widgets/Qt5Core) not found via pkg-config" >&2
    echo "Install Qt5 development packages or adjust PKG_CONFIG_PATH." >&2
    return 1
  fi
  CFLAGS="$(pkg-config --cflags Qt5Widgets Qt5Core)"
  LDFLAGS="$(pkg-config --libs Qt5Widgets Qt5Core)"
  g++ -fPIC -std=c++17 $CFLAGS main.cpp mainwindow.cpp coffee_fsm.cpp -o qt_coffee $LDFLAGS
  echo "Built: qt_coffee/qt_coffee"
}

case "$TARGET" in
  all)
    build_console
    build_gui
    ;;
  console)
    build_console
    ;;
  gui)
    build_gui
    ;;
  *)
    usage
    ;;
esac

echo "Done."
