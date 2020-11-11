# gather-windows-macos

When connecting and disconnecting your MacBook to an external display your windows sometimes end on the laptop display. This tool will get all your windows to the external display (that is set as primary).

## How it works
The tool uses the fact that when you toggle display mirroring on and off MacOS gathers all your windows on the primary display.

## How to build
```
mkdir build
cmake -S . -B build/
cmake --build build --target all -- -j 12
```

## How to get binaries
You can download the binary from the Releases tab.
