# MHAA EEPROM Contract

Defines bounded byte operations over one nonvolatile memory resource. An Adapter reports the accessible capacity, validates offsets and distinguishes a completed write from one whose outcome is uncertain.

Implement `Memory` for one accessible nonvolatile region. Base range checks on instance capacity even if an offset fits in the public type.

## Where it fits

The EEPROM Contract defines the interface and observable behavior. A concrete MCU Adapter implements it using Hardware Definitions. The Core consumes a reference to the implementation. Future Devices will bind the selected Adapter to the Core for the application. This project depends on C++11 standard headers.

Add `include/` to the C++11 include path and start with `<eeprom/memory.hpp>`. The [technical guide](docs/index.md) covers the other public interfaces and integration obligations.

- [Interface semantics](docs/contract.md)
- [Portability and limits](docs/compatibility.md)
- [Worked example and build commands](docs/examples.md)
- [MIT License](LICENSE)

## Generate the API reference

Use Doxygen 1.18.0. From this repository root, create `build/` if it does not exist, then run `doxygen Doxyfile`.

```sh
mkdir -p build
doxygen Doxyfile
```

On PowerShell, use `New-Item -ItemType Directory -Force build` for the first command. Open `build/docs/html/index.html`. Mermaid diagrams render in a browser with access to the Mermaid CDN. GitHub Pages publication runs on published releases and on manual dispatches from `main` once Pages is enabled.
