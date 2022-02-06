%macro import 1
extern     _%1
%define     %1        _%1
%endmacro

; constants:

%define         SDL_QUIT                            0x100

%define         SDL_WINDOW_FULLSCREEN               0x00000001   ;     /**< fullscreen window */
%define         SDL_WINDOW_OPENGL                   0x00000002   ;         /**< window usable with OpenGL context */
%define         SDL_WINDOW_SHOWN                    0x00000004   ;          /**< window is visible */
%define         SDL_WINDOW_HIDDEN                   0x00000008   ;         /**< window is not visible */
%define         SDL_WINDOW_BORDERLESS               0x00000010   ;     /**< no window decoration */
%define         SDL_WINDOW_RESIZABLE                0x00000020   ;      /**< window can be resized */
%define         SDL_WINDOW_MINIMIZED                0x00000040   ;      /**< window is minimized */
%define         SDL_WINDOW_MAXIMIZED                0x00000080   ;      /**< window is maximized */
%define         SDL_WINDOW_INPUT_GRABBED            0x00000100   ;  /**< window has grabbed input focus */
%define         SDL_WINDOW_INPUT_FOCUS              0x00000200   ;    /**< window has input focus */
%define         SDL_WINDOW_MOUSE_FOCUS              0x00000400   ;    /**< window has mouse focus */
%define         SDL_WINDOW_FULLSCREEN_DESKTOP       0x00001001   ;       ;( SDL_WINDOW_FULLSCREEN | 0x00001000 )
%define         SDL_WINDOW_FOREIGN                  0x00000800   ;        /**< window not created by SDL */
%define         SDL_WINDOW_ALLOW_HIGHDPI            0x00002000   ;  /**< window should be created in high-DPI mode if supported.
                                                                 ; ;On macOS NSHighResolutionCapable must be set true in the
                                                                 ; ;application's Info.plist for this to have any effect. */
%define         SDL_WINDOW_MOUSE_CAPTURE            0x00004000   ;  /**< window has mouse captured (unrelated to INPUT_GRABBED) */
%define         SDL_WINDOW_ALWAYS_ON_TOP            0x00008000   ;  /**< window should always be above others */
%define         SDL_WINDOW_SKIP_TASKBAR             0x00010000   ;  /**< window should not be added to the taskbar */
%define         SDL_WINDOW_UTILITY                  0x00020000   ;  /**< window should be treated as a utility window */
%define         SDL_WINDOW_TOOLTIP                  0x00040000   ;  /**< window should be treated as a tooltip */
%define         SDL_WINDOW_POPUP_MENU               0x00080000   ;  /**< window should be treated as a popup menu */
%define         SDL_WINDOW_VULKAN                   0x10000000   ;  /**< window usable for Vulkan surface */
%define         SDL_WINDOW_METAL                    0x20000000   ;    /**< window usable for Metal view */
%define         SDL_WINDOWPOS_UNDEFINED             0x1FFF0000   ;    /**< window position undefined */


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






