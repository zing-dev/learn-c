- c90

- c89

- iso9899:1990
> Support all ISO C90 programs (certain GNU extensions that conflict with ISO C90 are disabled). Same as -ansi for C code.

- iso9899:199409
> ISO C90 as modified in amendment 1.
>
- c99

- c9x

- iso9899:1999

- iso9899:199x
> ISO C99. Note that this standard is not yet fully supported; see http://gcc.gnu.org/c99status.html for more information. The names `c9x' and `iso9899:199x' are deprecated.

- c1x
> ISO C1X, the draft of the next revision of the ISO C standard. Support is limited and experimental and features enabled by this option may be changed or removed if changed in or removed from the standard draft.

- gnu90

- gnu89
> GNU dialect of ISO C90 (including some C99 features). This is the default for C code.

- gnu99

- gnu9x
> GNU dialect of ISO C99. When ISO C99 is fully implemented in GCC, this will become the default. The name `gnu9x' is deprecated.

- gnu1x
> GNU dialect of ISO C1X. Support is limited and experimental and features enabled by this option may be changed or removed if changed in or removed from the standard draft.
>
- c++98
> The 1998 ISO C++ standard plus amendments. Same as -ansi for C++ code.

- gnu++98
> GNU dialect of -std=c++98. This is the default for C++ code.

- c++0x
> The working draft of the upcoming ISO C++0x standard. This option enables experimental features that are likely to be included in C++0x. The working draft is constantly changing, and any feature that is enabled by this flag may be removed from future versions of GCC if it is not part of the C++0x standard.

- gnu++0x
> GNU dialect of -std=c++0x. This option enables experimental features that may be removed in future versions of GCC.
