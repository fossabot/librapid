<p align="center">
<img src="https://github.com/LibRapid/librapid_bin/blob/master/branding/LibRapid_light.png#gh-light-mode-only" width="800">
</p>

<p align="center">
<img src="https://github.com/LibRapid/librapid_bin/blob/master/branding/LibRapid_dark.png#gh-dark-mode-only" width="800">
</p>

![C++ Version](https://img.shields.io/badge/C++-17/22-purple.svg?style=flat&logo=c%2B%2B) ![License](https://img.shields.io/badge/License-MIT-orange.svg?style=flat) [![Discord](https://img.shields.io/discord/848914274105557043?color=blue&label=Discord&logo=Discord)](https://discord.gg/cGxTFTgCAC)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FLibRapid%2Flibrapid.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FLibRapid%2Flibrapid?ref=badge_shield)

---

[![Compile](https://github.com/LibRapid/librapid/actions/workflows/compile.yaml/badge.svg)](https://github.com/LibRapid/librapid/actions/workflows/compile.yaml) \
[![Documentation Build](https://github.com/LibRapid/librapid/actions/workflows/build-docs.yaml/badge.svg)](https://github.com/LibRapid/librapid/actions/workflows/build-docs.yaml) \
[![Documentation Online](https://github.com/LibRapid/librapid/actions/workflows/static.yaml/badge.svg)](https://librapid.github.io/librapid/md_librapid__r_e_a_d_m_e.html)

---

# What is LibRapid?

LibRapid is a high performance Array library, supporting a wide range of optimised calculations which can be performed
on the CPU or GPU (via CUDA). All calculations are vectorised with SIMD instructions and are run on multiple threads (if
necessary) to make them as fast as possible on any given machine.

There are also a wide range of helper functions and classes to aid the development of your own project.

LibRapid is highly templated, meaning it can conform to exactly your needs with minimal compile-times and even support
for custom data types.

# Documentation

<a href="https://librapid.github.io/librapid/md_librapid__r_e_a_d_m_e.html" target="_blank"><b>Latest
Documentation</b></a>

LibRapid uses [Doxygen](https://doxygen.nl/) and [Doxygen Awesome CSS](https://github.com/jothepro/doxygen-awesome-css)
to automatically generate the documentation.

# Current Development Stage

At the current point in time, LibRapid C++ is under rapid development by
me ([pencilcaseman](https://github.com/Pencilcaseman)).

I am currently doing my A-Levels and do not have time to work on the library as much as I would like, so if you or
someone you know might be willing to support the development of the library, feel free to create a pull request or chat
to us on [Discord](https://discord.com/invite/cGxTFTgCAC). Any help is greatly appreciated!

## [Roadmap](https://github.com/orgs/LibRapid/projects/5/views/1)

The [roadmap](https://github.com/orgs/LibRapid/projects/5/views/1) is a rough outline of what I want to get implemented
in the library and by what point, but **please don't count on features being implemented quickly** -- I can't promise
I'll have the time to implement everything as soon as I'd like... (I'll try my best though!)

If you have any feature requests or suggestions, feel free to create an issue describing it. I'll try to get it working
as soon as possible. If you really need something implemented quickly, a small donation would be appreciated, and would
allow me to bump it to the top of my list of features.

# Future Plans

My goal for LibRapid is to make it faster and easier to use than existing libraries, such as Eigen and XTensor. I plan
to develop an extensive testing and benchmarking suite alongside the code base, to ensure that everything is running as
fast as possible.

My main goal for the future is to implement as many features as possible, while maintaining the high performance
LibRapid requires.

# External Dependencies

LibRapid has a few external dependencies to improve functionality and performance. Some of these are optional, and can
be included with a CMake option. The following is a list of the external dependencies and their purpose (these are all
submodules of the library. You don't need to do anything different):

- Required
    - [fmt](https://github.com/fmtlib/fmt) - Advanced string formatting
    - [scnlib](https://github.com/eliaskosunen/scnlib) - Advanced string parsing
    - [Vc](https://github.com/VcDevel/Vc) - SIMD library
- Optional
    - [OpenMP](https://www.openmp.org/) - Multi-threading library
    - [CUDA](https://developer.nvidia.com/cuda-zone) - GPU computing library
    - [mpfr](https://github.com/Pencilcaseman/mpfr) - Arbitrary precision numbers (integer, real, rational)

# Star History

<div align="center">
  <a href="https://star-history.com/#Librapid/librapid/#date">
    <img src="https://api.star-history.com/svg?repos=LibRapid/librapid&type=Date" alt="Star History" width="700">
  </a>
</div>

# Contributors

<div align="center">
  <a href="https://github.com/LibRapid/librapid/graphs/contributors">
    <img src="https://contrib.rocks/image?repo=LibRapid/librapid&max=300&columns=20" alt="Contributors">
  </a>
</div>

# Support

Thanks to JetBrains for providing LibRapid with free licenses for their amazing tools!

<p align="center">
  <a href="https://www.jetbrains.com">
    <img src="https://devclass.com/wp-content/uploads/2018/12/jetbrains-variant-4.png" alt="JetBrains" width="200"/>
  </a>
</p>


## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FLibRapid%2Flibrapid.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FLibRapid%2Flibrapid?ref=badge_large)