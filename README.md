# gather-windows-macos

When connecting and disconnecting your MacBook to an external display your windows sometimes end up on the laptop display. This tool will get all your windows to the external display (that is set as primary).

## How it works
The tool uses the fact that when you toggle display mirroring on and off macOS gathers all your windows on the primary display.

## How to get the binary
You can download the binary from the Releases tab.

## How to use
Just run it from your shell prompt! Want a clickable icon? Use Automator!

## How to build
```
mkdir build
cmake -S . -B build/
cmake --build build --target all -- -j 12
```
