
/*
==========================================
    Copyright 2017-2018 Dynamic_Static
        Patrick Purcell
    Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "Dynamic_Static/System/Defines.hpp"
#if defined(DYNAMIC_STATIC_SYSTEM_OPENGL_ENABLED)

#include "Dynamic_Static/Core/StringUtilities.hpp"
#include "Dynamic_Static/System/OpenGL/Defines.hpp"
#include "Dynamic_Static/System/OpenGL/Object.hpp"
#include "Dynamic_Static/System/OpenGL/Shader.hpp"

#include "gsl/span"

#include <utility>

namespace Dynamic_Static {
namespace System {
namespace OpenGL {

    /*
    * Provides high level control over an OpenGL program.
    */
    class Program final
        : public Object
    {
    public:
        /*
        * Constructs an instance of Program.
        */
        inline Program()
        {
            mName = "Program (null)";
        }

        /*
        * Constructs an instance of Program.
        */
        inline Program(const gsl::span<Shader>& shaders)
        {
            mName = "Program";
            dst_gl(mHandle = glCreateProgram());
            for (const auto& shader : shaders) {
                dst_gl(glAttachShader(mHandle, shader.get_handle()));
            }
            dst_gl(glLinkProgram(mHandle));
            GLint linkStatus = 0;
            dst_gl(glGetProgramiv(mHandle, GL_LINK_STATUS, &linkStatus));
            if (linkStatus != GL_TRUE) {
                // TODO : dst::core logging...
                std::cerr
                    << "Failed to link program" << std::endl
                    << get_info_log(mHandle) << std::endl
                    << std::endl;
                dst_gl(glDeleteProgram(mHandle));
                mHandle = 0;
            }
        }

        /*
        * Moves an instance of Program.
        * @param [in] other The Program to move from
        */
        inline Program(Program&& other)
        {
            *this = std::move(other);
        }

        inline ~Program()
        {
            if (mHandle) {
                dst_gl(glDeleteProgram(mHandle));
            }
        }

        /*
        * Moves an instance of Program.
        * @param [in] other The Program to move from
        * @return This Program
        */
        inline Program& operator=(Program&& other)
        {
            if (this != &other) {
                Object::operator=(std::move(other));
            }
            return *this;
        }

    public:
        /*
        * Gets a uniform location for this Program.
        * @param [in] uniformName The name of the uniform to get the location for
        * @return The location for the given uniform
        */
        inline GLint get_uniform_location(dst::string_view uniformName) const
        {
            // TODO : Setup dst::StringView to ensure null termination.
            //        See https://stackoverflow.com/a/41288372/3453616
            GLint uniformLocation = 0;
            dst_gl(uniformLocation = glGetUniformLocation(mHandle, std::string(uniformName).c_str()));
            return uniformLocation;
        }

        /*
        * Gets this Program's info log.
        * @return This Program's info log
        */
        inline std::string get_info_log() const
        {
            return get_info_log(mHandle);
        }

        /*
        * Binds this Program.
        */
        inline void bind() const
        {
            dst_gl(glUseProgram(mHandle));
        }

        /*
        * Unbinds the current Program.
        */
        inline void unbind() const
        {
            dst_gl(glUseProgram(0));
        }

        /*
        * Gets a given Program's info log.
        * @param [in] shader The Program to get the info log for
        * @return The given Program's info log
        */
        static inline std::string get_info_log(const Program& program)
        {
            return get_info_log(program.get_handle());
        }

        /*
        * Gets a given Program's info log.
        * @param [in] handle The handle to the Program to get the info log for
        * @return The given Program's info log
        */
        static inline std::string get_info_log(GLuint handle)
        {
            return gl::get_info_log(handle, glGetProgramiv, glGetProgramInfoLog);
        }
    };

} // namespace OpenGL
} // namespace System
} // namespace Dynamic_Static

#endif // defined(DYNAMIC_STATIC_OPENGL_ENABLED)


#if 0
OpenGL Error[1282:invalid operation]
c:\development\dynamic_static\dynamic_static.system\examples.ex\glgears.cpp @ line 541
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0])

    OpenGL Error[1282:invalid operation]
    c:\development\dynamic_static\dynamic_static.system\examples.ex\glgears.cpp @ line 542
    glUniform3fv(lightDirectionLocation, 1, &glm::normalize(lightDirection)[0])

    OpenGL Error[1282:invalid operation]
    c:\development\dynamic_static\dynamic_static.system\examples.ex\glgears.cpp @ line 550
    glUniformMatrix4fv(modelViewLocation, 1, GL_FALSE, &modelView[0][0])

    OpenGL Error[1282:invalid operation]
    c:\development\dynamic_static\dynamic_static.system\examples.ex\glgears.cpp @ line 551
    glUniform4fv(colorLocation, 1, &gear.color[0])
#endif