Courgette
=========

This is a standalone build of ``courgette`` from the ``chromium`` project.
The purpose is to allow building ``courgette`` without too much hasle in
embedded frameworks like ``Yocto``/``OE`` and ``buildroot``.

Building
--------

To build courgette, install ``meson`` and configure the project:

```
meson out
```

Then run ninja to build and install:

```
ninja -C out
sudo ninja -C out install
```
