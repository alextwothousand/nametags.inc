# nametags.inc
nametags.inc - basic custom nametags

nametags.inc was written to be used with my script. I decided to release it just because I could - besides, it was completely independent of the script and could function without it, so why not?

you'll need strlib by slice, y_hooks by y_less, streamer by incognito and foreach also by y_less (however I give credit where credit is due and that goes to the contributors as well).

I used these includes as they would make it quicker for me to write the include. You could easily make this script independent of all its dependencies, other than streamer.

## Notes:
-  If you are already setting the player's color to -1 under OnPlayerConnect **OR** you're using fixes.inc you can get rid of lines 85 - 90.
-  If you want to modify the draw distance for the nametags you can define NT_DISTANCE in your script with a value below or greater than 20.0 **before you include the script**.
- You should probably include this after all the dependencies.
- You can work on this and modify it as you wish. Just keep the credits in, will you? :)

## Downloads:
- strlib (https://forum.sa-mp.com/showthread.php?t=362764)
- streamer (https://github.com/samp-incognito/samp-streamer-plugin/releases)
- foreach (you probably already have this)
- y_hooks comes packaged with YSI
