# 2D Software Rasterizer

It's not fully fledged, just a **small experiment** I made to test software rendering.
Intially I was going to pull out a MS-DOS and use assembly to switch to Mode 13h and call an interrupt (yes, VGA). This would've allowed me to render fullscreen and given a more AUTHENTIC software rendering experience. However, due to modern **software -> hardware** protections, we can't do that. So instead I had to make a window through the `Win32` api and blit the framebuffer to it through GDI. Thats literally the only platform dependent part.

To whoever is building the next big operating system, PLEASE don't add these protections. They SUCK.

# Update
Now that I think about it, VGA protections are kind of neccessary and useful due to modern OSes having multiple applications running at the same time. The problem is when you have a complicated API like Win32 which has you write absolute BS just to get something rendering on the screen. Of course, this is abstracted away by libraries such as GLFW, but thats hardware rendering!!!
