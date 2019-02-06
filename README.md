# RT

RT is a 42 project developped by squiquem, sederet, asarasy and qsebasti, which is designed to further student's understanding of the concepts behind ray tracing.
____
## Scene

The scene is defined by light, camera, material and objects (sphere, cone, plane, quadric, box).<br/>
____
## Features

- The scene can be modified in real-time and the program uses multithreading to speed up calculations.<br/>
- Every object can be modified by its type, color or variable as reflection, transparency, coefficient of refraction and more.<br />
- Any object can have a texture (xpm format, perlin sound, checkerboard, etc.).<br/>
- The program supports filters as sepia or black and white and more.<br/>
- Change the reflection max value for all the reflective surfaces.<br/>
- Increase or decrease antialiasing value.<br/>
- Funny (in my opinion) loading screen while waiting for changes to be applied.<br/>
____
## Keys

### Camera movements

Step to the left / right :   <td align="right"><kbd>&nbsp;A&nbsp;</kbd>/<kbd>&nbsp;◄&nbsp;</kbd> || <kbd>&nbsp;D&nbsp;</kbd>/<kbd>&nbsp;►&nbsp;</kbd></td><br/>
Step forward / backward :   <td align="right"><kbd>&nbsp;W&nbsp;</kbd>/<kbd>&nbsp;S&nbsp;</kbd></td><br/>
Step up / down :    <kbd>&nbsp;▲&nbsp;</kbd>/<kbd>&nbsp;▼&nbsp;</kbd><br/>
Rotate to the left / right : <kbd>&nbsp;Q&nbsp;</kbd>/<kbd>&nbsp;E&nbsp;</kbd><br/>
Apply changes : <kbd>&nbsp;Return&nbsp;</kbd>
____

## How to use it

You can apply any filter at any time with just one click on the filter and/or the cartoon effect and the apply button (on screen or the 'return' key). Also the antialiasing lvl.<br/>
<br/>
For any change on an object, first select an object.<br/>
Then pick up the type of material (uniform color, wood-like pattern, perlin noise, etc).<br/>
Third, choose the color (some material types need 2 selected colors).<br/>
Finally, apply the changes.<br/>
<br/>
Repeat these instructions for every object to change.<br/>
<br/>
On 3rd tabulation you can change the variables for an object.
____
## Installing and launch

    git clone vogsphere@vogsphere.42.fr:intra/2018/activities/rt/squiquem ~/RT
    cd ~/RT && make && ./rt/scenes/scene1.xml

____
We do not own any right on every used image in the program.