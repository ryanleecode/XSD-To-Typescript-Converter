# XSD To Typescript Converter

XSD to Typescript converter is a tool that converts XSD type definitions into Typescript _types_ and _interface_ definitions.

## Setup

### Prerequisites

#### Conan

1. Install the [conan](https://docs.conan.io/en/latest/installation.html) package manager.
2. Add the following sources to your conan remotes

```
conan remote add conan-center https://conan.bintray.com
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan remote add fruit https://api.bintray.com/conan/google/fruit
```

#### CMake

1. Install any version of [CMake](https://cmake.org/download/) >= **3.1**

#### XSD Files

Create an XSD file with the name `Elements.xsd` and drop it in `<rootdir>/src`. An example file is provided [here](SampleXSD.xml).

## Building

```
cd src

conan install . -s build_type=Debug --install-folder=cmake-build-debug --build missing -s compiler.libcxx=libstdc++11

cd cmake-build-debug

cmake ../

make
```

## Running

```
cd <rootdir>/src/cmake-build-debug/bin/
./xsdtotypescript
```

The generated Typescript types will appear in `std::out`

## Tests

```
cd <rootdir>/src/cmake-build-debug/bin/
./tsgen_test
./util_test
./xmlparse_test
```

## Roadmap

- [ ] CLI Support
- [ ] NPM Package

- [ ] XSD Simple Type
  - [ ] String Type
    - [x] Basic
    - [x] Enumeration
    - [ ] Pattern
  - [x] Decimal Type
  - [ ] Integer Type
    - [x] Basic
    - [ ] Enumeration
    - [ ] Min/Max Inclusive
    - [ ] Pattern
  - [x] DateTime Type
- [x] XSD Complex Type
  - [x] Basic
  - [x] XSD Sequence Type
- [x] XSD Element Type
