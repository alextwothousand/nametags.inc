# nametags.inc

[![sampctl](https://shields.southcla.ws/badge/sampctl-nametags.inc-2f2f2f.svg?style=for-the-badge)](https://github.com/infin1tyy/nametags.inc)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->
nametags.inc was written to be used with my script. I decided to release it just because I could - besides, it was completely independent of the script and could function without it, so why not?

## Installation

Simply install to your project:

```bash
sampctl package install infin1tyy/nametags.inc
```

Include in your code and begin using the library:

```pawn
#include <nametags.inc>
```

## Usage

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->
-  If you are already setting the player's color to -1 under OnPlayerConnect **OR** you're using fixes.inc you can get rid of lines 85 - 90.
-  If you want to modify the draw distance for the nametags you can define NT_DISTANCE in your script with a value below or greater than 20.0 **before you include the script**.

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
