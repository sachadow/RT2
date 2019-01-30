# RT

RT is a 42 project developped by squiquem, sederet, asarasy and qsebasti, which is designed to further students' understanding of the concepts behind raytracing.

The program use scenes as `.xml` files built with the following elements.

## 1. Camera

    CAM {position: (0, 0, -2000), direction: (0, 0, 1)};

- `position` defined by (x, y, z) values as absolute coordinates
- `direction` is a vector (x, y, z) with normalized values

    **\/!\ Scene files must contain only 1 camera /!\\**
___

## 2. Light

    LIGHT {position: (640, 240, -1000), intensity: (255, 255, 255)};

- `position` define (x, y, z) values as absolute coordinates
- `intensity` is basically the color of the light defined by each component (r, g, b) of the color, each one between 0 and 255

    **\/!\ Scene files must contain at least 1 light /!\\**

___

## 3. Material

    MAT {diffusion: (255, 255, 0), reflexion: 0, specvalue: 100, specpower: 50};

- `diffusion` is basically the color of the material itself defined by each component (r, g, b) of the color, each one between 0 and 255
- `specvalue` and `specpower` between 0 and 100 define the brightness
- `reflexion` between 0 and 100 is the reflection coefficent

    **\/!\ Scene files must contain at least 1 material and the first material number start at 0 /!\\**

___

## 4. Objects

Scene file can contain zero or more of the following objects :

1. Sphere

        SPHERE {center: (233, 290, 0), radius: 100, mat: 0};  

    - `center` define (x, y, z) values as absolute coordinates of the sphere's center in the scene  
    - `radius` is the sphere's radius

        **\/!\ Radius must be > 0 /!\\**

2. Cylinder

        CYLINDER {direction: (1, 0, 1), axispoint: (500, 600, 0), radius: 100, mat: 0};

    - `direction` is a vector (x, y, z) with normalized values
    - `axispoint` define (x, y, z) values as absolute coordinates of the cylinder's center in the scene
    - `radius` is the cylinder's radius   

        **\/!\ Radius must be > 0 /!\\**

3. Cone

        CONE {direction: (0, 1, 0), center: (500, 300, 200, angle: 15, mat: 0)};   

    - `direction` is a vector (x, y, z) with normalized values
    - `center` define (x, y, z) values as absolute coordinates of the cone's center in the scene
    - `angle` defines the cone's angle from its center

        **\/!\ Angle must be > 0 and < 70 /!\\**  

4. Plane

        PLANE {normale: (0, 0, 1), d: -1500, mat: 1};

    - `normale` is a vector (x, y, z) with normalized values of the plane's normale
    - `d` comes from the equation of a plane

**\/!\ Every vector must have at least 1 parameter != 0 /!\\** 

## Bonus

You can apply a translation or a rotation to any object by adding the related option at the end of the object declaration

    +T (0, 0 , 1000)

Translate the previous object on (x, y, z) axis with absolute values

    +R (0, 90, 0)

Rotate the previous object on (x, y, z) axis by an angle  


## Installing and launch

    git clone vogsphere@vogsphere.42.fr:intra/2018/activities/rt/squiquem ~/RT
    cd ~/RT
    make && ./rt/scenes/scene1.xml

