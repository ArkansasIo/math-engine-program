# Product Design
The application has two layers. The vm1024 C++ library provides the simulated CPU, GPU, memory, ISA, quantum subsystem, and Math Engine bridge. The vm1024-dashboard executable provides a native Windows command-center presentation layer.
### Visual system
Dark industrial-blue background; cyan compute telemetry; green healthy-state indicators; purple accelerator/quantum panels. The layout is deliberately dense like a workstation control console.
### Execution model
Windows x64 host -> VM runtime -> classical/quantum execution models -> Math Engine registry. The VM is not a hypervisor and does not execute arbitrary guest-native code on the host.