#pragma once
#include <GL/glew.h>
#include <shader.hpp>

class Vbo
{
public:
    void* data_;
    GLuint handle_;
    GLenum target_;
    int len_;

    Vbo() {}
    Vbo(GLenum target);
    Vbo(GLenum target, void* data, size_t data_size, GLenum usage);
    ~Vbo();
    
    GLenum& target();
    int& len();
    void gen_buffers();
    void bind();
    virtual void unbind();
    void set_data(GLenum, void* data, size_t data_size, GLenum usage);
    void*& data();

    static void unbind(GLenum target)
    {
        glBindBuffer(target, 0);
    }
};

class ArrayBuffer : public Vbo
{
    size_t size_;
    GLenum type_;
    bool normalized_;
    size_t stride_;
public:
    ArrayBuffer(void* data, size_t data_size, GLenum usage);

    ArrayBuffer& set_size(size_t size);
    ArrayBuffer& set_type(GLenum type);
    ArrayBuffer& set_normalized(bool normalized);
    ArrayBuffer& set_stride(size_t stride);

    size_t& size();
    GLenum& type();
    bool& normalized();
    size_t& stride();

    virtual void unbind() override;
};
