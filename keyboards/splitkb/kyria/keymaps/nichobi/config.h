#pragma once

#define MK_KINETIC_SPEED            // Enable kinetic mode
#define MOUSEKEY_INITIAL_SPEED 300  // Initial speed of the cursor in pixel per second
#define MOUSEKEY_BASE_SPEED    2000 // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_INTERVAL      5    // Time between cursor movements in milliseconds

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS     1 // Initial number of movements of the mouse wheel
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS        32 // Maximum number of movements at which acceleration stops
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8  // Decelerated wheel movements
