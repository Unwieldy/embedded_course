# Lockbox
## Task
Write an electronic lock program for the Pico.  
## Behavior  
- The electronic lock should indicate its state on an LCD display (locked, unlocked).  
- The lock should be unlocked by a keycode of at least four digits.  
- The code should be entered using a keypad with at least four buttons.  
- The keycode should be rolling, which means that as long as a correct sequence has been entered (disregarding previous erroneous entries), the lock should unlock.  
- The lock should remain unlocked for a duration of 10 seconds after it has been unlocked.  


## Bonus assignments
- Allow for the keycode to be changed after a successful unlock.
- Allow for multiple keycodes.
- Detect bruteforce attempts
    - Block bruteforce attempts
- Log entires
- Add audio feedback
- Do not store keycode on the device.
