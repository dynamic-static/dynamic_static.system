
/*
==========================================
    Copyright (c) 2017 Dynamic_Static
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/System/Defines.hpp"

#include <bitset>

namespace Dynamic_Static {
namespace System {

    /**
     * Provides methods for Keyboard queries.
     */
    class Keyboard final
    {
    public:
        /**
         * Specifies Keyboard keys.
         */
        enum class Key
        {
            // NOTE : The following table shows the symbolic constant names, hexadecimal values,
            //         and mouse or keyboard equivalents for the virtual-key codes used by Windows.
            //         The codes are listed in numeric order.
            // http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

            // Left                 = 0x01,
            // Right                = 0x02,

            ControlBreak         = 0x03,

            // Middle               = 0x04,
            // X1                   = 0x05,
            // X2                   = 0x06,

            Backspace            = 0x08,
            Tab                  = 0x09,
            Clear                = 0x0c,
            Enter                = 0x0d,
            Shift                = 0x10,
            Ctrl                 = 0x11,
            Alt                  = 0x12,
            Pause                = 0x13,
            CapsLock             = 0x14,

            IMEKanaMode          = 0x15,
            IMEHanguelMode       = 0x15,
            IMEHangulMode        = 0x15,
            IMEHanjaMode         = 0x19,
            IMEKanjiMode         = 0x19,

            Escape               = 0x1b,

            IMEConvert           = 0x1c,
            IMENonConvert        = 0x1d,
            IMEAccept            = 0x1e,
            IMEModeChangeRequest = 0x1f,

            SpaceBar             = 0x20,
            PageUp               = 0x21,
            PageDown             = 0x22,
            End                  = 0x23,
            Home                 = 0x24,

            LeftArrow            = 0x25,
            UpArrow              = 0x26,
            RightArrow           = 0x27,
            DownArrow            = 0x28,

            Select               = 0x29,
            Print                = 0x2a,
            Execute              = 0x2b,
            PrintScreen          = 0x2c,
            Insert               = 0x2d,
            Delete               = 0x2e,
            Help                 = 0x2f,

            Zero                 = 0x30,
            One                  = 0x31,
            Two                  = 0x32,
            Three                = 0x33,
            Four                 = 0x34,
            Five                 = 0x35,
            Six                  = 0x36,
            Seven                = 0x37,
            Eight                = 0x38,
            Nine                 = 0x39,

            A                    = 0x41,
            B                    = 0x42,
            C                    = 0x43,
            D                    = 0x44,
            E                    = 0x45,
            F                    = 0x46,
            G                    = 0x47,
            H                    = 0x48,
            I                    = 0x49,
            J                    = 0x4a,
            K                    = 0x4b,
            L                    = 0x4c,
            M                    = 0x4d,
            N                    = 0x4e,
            O                    = 0x4f,
            P                    = 0x50,
            Q                    = 0x51,
            R                    = 0x52,
            S                    = 0x53,
            T                    = 0x54,
            U                    = 0x55,
            V                    = 0x56,
            W                    = 0x57,
            X                    = 0x58,
            Y                    = 0x59,
            Z                    = 0x5a,

            LeftWindow           = 0x58,
            RightWindow          = 0x5c,
            Applications         = 0x5d,
            PowerSleep           = 0x5f,

            NumPad0              = 0x60,
            NumPad1              = 0x61,
            NumPad2              = 0x62,
            NumPad3              = 0x63,
            NumPad4              = 0x64,
            NumPad5              = 0x65,
            NumPad6              = 0x66,
            NumPad7              = 0x67,
            NumPad8              = 0x68,
            NumPad9              = 0x69,

            Multiply             = 0x6a,
            Add                  = 0x6b,
            Seperator            = 0x6c,
            Subtract             = 0x6d,
            Decimal              = 0x6e,
            Divide               = 0x6f,

            F1                   = 0x70,
            F2                   = 0x71,
            F3                   = 0x72,
            F4                   = 0x73,
            F5                   = 0x74,
            F6                   = 0x75,
            F7                   = 0x76,
            F8                   = 0x77,
            F9                   = 0x78,
            F10                  = 0x79,
            F11                  = 0x7a,
            F12                  = 0x7b,
            F13                  = 0x7c,
            F14                  = 0x7d,
            F15                  = 0x7e,
            F16                  = 0x7f,
            F17                  = 0x80,
            F18                  = 0x81,
            F19                  = 0x82,
            F20                  = 0x83,
            F21                  = 0x84,
            F22                  = 0x85,
            F23                  = 0x86,
            F24                  = 0x87,

            NumLock              = 0x90,
            ScrollLock           = 0x91,

            LeftShift            = 0xa0,
            RightShift           = 0xa1,
            LeftControl          = 0xa2,
            RightControl         = 0xa3,

            LeftMenu             = 0xa4,
            RightMenu            = 0xa5,
            BrowserBack          = 0xa6,
            BrowserForward       = 0xa7,
            BroserRefresh        = 0xa8,
            BrowserStop          = 0xa9,
            BrowserSearch        = 0xaa,
            BrowserFavorites     = 0xab,
            BrowserHome          = 0xac,

            VolumeMute           = 0xad,
            VolumeDown           = 0xae,
            VolumeUp             = 0xaf,

            MediaNextTrack       = 0xb0,
            MediaPreviousTrack   = 0xb1,
            MediaStop            = 0xb2,
            MediaPlayPause       = 0xb3,

            LaunchMail           = 0xb4,
            LaunchMediaSelect    = 0xb5,
            LaunchApp_1          = 0xb6,
            LaunchApp_2          = 0xb7,

            OEM_SemiColon        = 0xba, // NOTE : Can vary by keyboard, ';:' is US standard
            OEM_Plus             = 0xbb,
            OEM_Comma            = 0xbc,
            OEM_Minus            = 0xbd,
            OEM_Period           = 0xbe,
            OEM_ForwardSlash     = 0xbf, // NOTE : Can vary by keyboard, '/?' is US standard
            OEM_Tilde            = 0xc0, // NOTE : Can vary by keyboard, '`~' is US standard
            OEM_OpenBracket      = 0xdb, // NOTE : Can vary by keyboard, '[{' is US standard
            OEM_BackSlash        = 0xdc, // NOTE : Can vary by keyboard, '\|' is US standard
            OEM_CloseBracket     = 0xdd, // NOTE : Can vary by keyboard, ']}' is US standard
            OEM_Quote            = 0xde, // NOTE : Can vary by keyboard, ''"' is US standard
            OEM_Misc             = 0xdf, // NOTE : Varies by keyboard
            OEM_102              = 0xe2,

            Process              = 0xe5,

            Packet               = 0xe7, // NOTE : Used to pass Unicode characters as keystrokes

            Attn                 = 0xf6,
            CrSel                = 0xf7,
            ExSel                = 0xf8,
            EraseEOF             = 0xf9,
            Play                 = 0xfa,
            Zoom                 = 0xfb,
            PA1                  = 0xfd,

            OEM_Clear            = 0xfe,

            Unknown,
            Count,
            Any,
        };

        /**
         * Represents a Keyboard's state at a single moment.
         */
        struct State final
        {
        public:
            static constexpr bool Up = false;
            static constexpr bool Down = true;
            using KeySet = std::bitset<static_cast<size_t>(Key::Count)>;

        private:
            KeySet mKeys;

        public:
            /**
             * Gets a value indicating whether or not a given Key is down.
             * @param [in] key The Key to check
             * @return Whether or not the given Key is down
             */
            bool operator[](Key key) const;

            /**
             * Sets a value indicating whether or not a given Key is down.
             * @param [in] key The Key to set
             * @return Whether or not the given Key is down
             */
            KeySet::reference operator[](Key key);

            /**
             * Gets a value indicating whether or not a given Key is down.
             * @param [in] key The Key to check
             * @return Whether or not the given Key is down
             */
            bool operator[](size_t key) const;

            /**
             * Sets a value indicating whether or not a given Key is down.
             * @param [in] key The Key to set
             * @return Whether or not the given Key is down
             */
            KeySet::reference operator[](size_t key);

        public:
            /**
             * Resets this Keyboard::State.
             */
            void reset();
        };

    private:
        State mCurrent;
        State mPrevious;

    public:
        /**
         * Gets a value indicating whether or not a given Key is up.
         * @param [in] key The Key to check
         * @return Whether or not the given Key is up
         */
        bool up(Key key) const;

        /**
         * Gets a value indicating whether or not a given Key is down.
         * @param [in] key The Key to check
         * @return Whether or not the given Key is down
         */
        bool down(Key key) const;

        /**
         * Gets a value indicating whether or not a given Key has been held.
         * @param [in] key The Key to check
         * @return Whether or not the given Key has been held
         */
        bool held(Key key) const;

        /**
         * Gets a value indicating whether or not a given Key has been pressed.
         * @param [in] key The Key to check
         * @return Whether or not the given Key has been pressed
         */
        bool pressed(Key key) const;

        /**
         * Gets a value indicating whether or not a given Key has been released.
         * @param [in] key The Key to check
         * @return Whether or not the given Key has been released
         */
        bool released(Key key) const;

        /**
         * Resets this Keyboard.
         */
        void reset();

    private:
        void update(const State& state);

    private:
        friend class Input;
    };

} // namespace System
} // namespace Dynamic_Static

namespace Dynamic_Static {
namespace System {

    /**
     * Converts a GLFW key to a Keyboard::Key.
     * @param [in] glfwJKey The GLFW key to convert to a Keyboard::Key
     * @return The converted Keyboard::Key
     */
    Keyboard::Key glfw_to_dst_key(int glfwKey);

} // namespace System
} // namespace Dynamic_Static
