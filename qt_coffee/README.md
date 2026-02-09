# Qt Coffee GUI (minimal)

This small demo implements a coffee ordering GUI backed by a minimal finite-state-machine (FSM).

State machine
- States: Idle -> Selected -> Brewing -> Done
- Actions: select a coffee type (Selected), `Start Brew` moves to `Brewing` and after a timer to `Done`.
- Options: strength (Mild/Strong), extra milk, oats milk, warm water. Brewing time adjusts by options and simulated temperature.

Build and run on Ubuntu (recommended)

1) Install dependencies (Ubuntu/Debian):

```bash
sudo ./install_deps.sh
```

2) Build with CMake (preferred):

```bash
mkdir -p qt_coffee/build
cd qt_coffee/build
cmake ..
make -j$(nproc)
```

3) Run:

```bash
./qt_coffee/qt_coffee
```

Alternatively use the provided quick build script:

```bash
chmod +x build_qt_coffee.sh
./build_qt_coffee.sh
```

Doxygen and code style

- Files were copied into `qt_coffee/include` (headers) and `qt_coffee/src` (sources) and include simple Doxygen-style comments in headers and source files.
- To generate documentation:

```bash
cd qt_coffee
mkdir -p docs && doxygen -g docs/Doxyfile && doxygen docs/Doxyfile
```

Notes and next steps
- The FSM implementation is intentionally simple and moc-free so it can be built without Qt's moc tooling. For a full Qt QStateMachine-based FSM we can refactor to use signals/slots and add moc integration via CMake.
- If you want real sensor integration (temperature), replace the simulated sensor in `mainwindow.cpp` with a real reader and call `m_fsm->setTemperature()`.

