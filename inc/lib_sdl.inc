%macro import 1
extern     _%1
%define     %1        _%1
%endmacro

; constants:

%define         SDL_QUIT            0x100


;#################################################################################
;#################################################################################
;                               SDL MAIN FUNC
;#################################################################################
;#################################################################################

; extern     _SDL_Init
; %define    SDL_Init        _SDL_Init
import       SDL_Init

; extern     _SDL_Quit
; %define    SDL_Quit        _SDL_Quit
import       SDL_Quit

; extern     _SDL_PollEvent
; %define    SDL_PollEvent        _SDL_PollEvent
import       SDL_PollEvent


;#################################################################################
;#################################################################################
;                           SDL WINDOW'S FUNCTIONS
;#################################################################################
;#################################################################################

; extern     _SDL_CreateWindow
; %define     SDL_CreateWindow        _SDL_CreateWindow
import       SDL_CreateWindow

;  extern     _SDL_CreateWindowFrom
; %define     SDL_CreateWindowFrom    _SDL_CreateWindowFrom
import       SDL_CreateWindowFrom

;  extern     _SDL_DestroyWindow
; %define     SDL_DestroyWindow       _SDL_DestroyWindow
import       SDL_DestroyWindow

;  extern     _SDL_GetWindowData
; %define     SDL_GetWindowData       _SDL_GetWindowData
import       SDL_GetWindowData

;  extern     _SDL_GetWindowFlags
; %define     SDL_GetWindowFlags      _SDL_GetWindowFlags
import       SDL_GetWindowFlags

;  extern     _SDL_GetWindowGrab
; %define     SDL_GetWindowGrab       _SDL_GetWindowGrab
import       SDL_GetWindowGrab

;  extern     _SDL_GetWindowPosition
; %define     SDL_GetWindowPosition   _SDL_GetWindowPosition
import       SDL_GetWindowPosition

;  extern     _SDL_GetWindowSize
; %define     SDL_GetWindowSize       _SDL_GetWindowSize
import       SDL_GetWindowSize

;  extern     _SDL_GetWindowTitle
; %define     SDL_GetWindowTitle      _SDL_GetWindowTitle
import       SDL_GetWindowTitle

;  extern     _SDL_HideWindow
; %define     SDL_HideWindow          _SDL_HideWindow
import       SDL_HideWindow

;  extern     _SDL_MaximizeWindow
; %define     SDL_MaximizeWindow    _SDL_MaximizeWindow
import       SDL_MaximizeWindow

;  extern     _SDL_MinimizeWindow
; %define     SDL_MinimizeWindow    _SDL_MinimizeWindow
import       SDL_MinimizeWindow

;  extern     _SDL_RestoreWindow
; %define     SDL_RestoreWindow        _SDL_RestoreWindow
import       SDL_RestoreWindow

;  extern     _SDL_RaiseWindow
; %define     SDL_RaiseWindow        _SDL_RaiseWindow
import       SDL_RaiseWindow

;  extern     _SDL_SetWindowData
; %define     SDL_SetWindowData      _SDL_SetWindowData
import       SDL_SetWindowData

;  extern     _SDL_SetWindowFullscreen
; %define     SDL_SetWindowFullscreen _SDL_SetWindowFullscreen
import       SDL_SetWindowFullscreen
                                    
;  extern     _SDL_SetWindowGrab
; %define     SDL_SetWindowGrab    _SDL_SetWindowGrab
import       SDL_SetWindowGrab

;  extern     _SDL_SetWindowIcon
; %define     SDL_SetWindowIcon    _SDL_SetWindowIcon
import       SDL_SetWindowIcon

;  extern     _SDL_SetWindowPosition
; %define     SDL_SetWindowPosition    _SDL_SetWindowPosition
import       SDL_SetWindowPosition

;  extern     _SDL_SetWindowSize
; %define     SDL_SetWindowSize    _SDL_SetWindowSize
import       SDL_SetWindowSize

;  extern     _SDL_SetWindowBordered
; %define     SDL_SetWindowBordered _SDL_SetWindowBordered
import       SDL_SetWindowBordered

;  extern     _SDL_SetWindowResizable
; %define     SDL_SetWindowResizable    _SDL_SetWindowResizable
import       SDL_SetWindowResizable

;  extern     _SDL_SetWindowTitle
; %define     SDL_SetWindowTitle    _SDL_SetWindowTitle
import       SDL_SetWindowTitle

;  extern     _SDL_ShowWindow
; %define     SDL_ShowWindow    _SDL_ShowWindow
import       SDL_ShowWindow



;#################################################################################
;#################################################################################
;                               SDL DATA STRUCTS
;#################################################################################
;#################################################################################


section .bss

; /** Application visibility event structure */
; typedef struct SDL_ActiveEvent {
; 	Uint8 type;	/**< SDL_ACTIVEEVENT */
; 	Uint8 gain;	/**< Whether given states were gained or lost (1/0) */
; 	Uint8 state;	/**< A mask of the focus states */
; } SDL_ActiveEvent;

; struc SDL_ActiveEvent 
;     .type       resb    1
;     .gain       resb    1
;     .state      resb    1
; endstruc

; typedef union SDL_Event {
; 	Uint8 type;
; 	SDL_ActiveEvent active;
; 	SDL_KeyboardEvent key;
; 	SDL_MouseMotionEvent motion;
; 	SDL_MouseButtonEvent button;
; 	SDL_JoyAxisEvent jaxis;
; 	SDL_JoyBallEvent jball;
; 	SDL_JoyHatEvent jhat;
; 	SDL_JoyButtonEvent jbutton;
; 	SDL_ResizeEvent resize;
; 	SDL_ExposeEvent expose;
; 	SDL_QuitEvent quit;
; 	SDL_UserEvent user;
; 	SDL_SysWMEvent syswm;
; } SDL_Event;

; struc SDL_Event 
;     .type       resb    1
;     .active     resb    3
    

; endstruc






