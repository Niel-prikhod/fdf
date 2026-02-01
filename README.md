*This project has been created as part of the 42 curriculum by dprikhod*

# Description

FDF (Fil De Fer - Wireframe) is a 3D wireframe viewer that reads height maps from `.fdf` files and renders them as wireframe models. The project implements a complete 3D to 2D projection pipeline using the MiniLibX graphics library.

The goal of this project is to:
- Parse map files containing height data and optional color information
- Transform 3D coordinates to 2D screen space using isometric projection
- Render wireframe models using efficient line drawing algorithms
- Provide a basic interactive 3D visualization system

## Features

- **Map Parsing**: Supports both height-only and height,color formats in `.fdf` files
- **Isometric Projection**: Fixed 3D to 2D transformation for wireframe rendering
- **Color Support**: Uses file-specified colors, defaults to white when not provided
- **Window Management**: Creates and manages graphical windows using MiniLibX
- **Memory Management**: Proper memory allocation and cleanup following 42 School norms

# Instructions

## Compilation

The project uses a custom Makefile with multiple build targets:

```bash
# Build the entire project (release mode)
make

# Build in debug mode with additional debugging information
make debug

# Clean build artifacts
make clean

# Full clean (remove executable)
make fclean

# Rebuild from scratch
make re

# Build dependencies individually
make -C libft      # Build libft library
make -C mlx_linux   # Build MiniLibX library
```

## Execution

```bash
# Run with a map file
./fdf test_maps/mars.fdf

# Available test maps
./fdf test_maps/42.fdf     # Simple test map
./fdf test_maps/elem.fdf   # Medium complexity
./fdf test_maps/julia.fdf  # Complex map
./fdf test_maps/mars.fdf   # Mars terrain data
```

### Map File Format

`.fdf` files contain space-separated values:

```
# Height only format
1 2 3
4 5 6
7 8 9

# Height,color format
1,0xFFFFFF 2,0xFF0000 3,0x00FF00
4,0x0000FF 5,0xFFFF00 6,0xFF00FF
```

## Requirements

- **Operating System**: Linux (tested on Arch Linux)
- **Compiler**: GCC with C11 support
- **Libraries**: 
  - libft (custom utility library)
  - MiniLibX (graphics library)
  - X11 development libraries
  - Math library (libm)

### Dependencies Installation (Arch Linux)

```bash
sudo pacman -S base-devel libx11 libxext
```

# Resources

## Technical References

- **[MiniLibX Documentation](https://github.com/42School/minilibx-linux)**: Graphics library reference
- **[42 School Norm](https://github.com/42School/norminette)**: Coding standards and guidelines
- **[Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)**: Line drawing implementation
- **[Isometric Projection](https://en.wikipedia.org/wiki/Isometric_projection)**: 3D to 2D transformation
- **[libft Reference](https://github.com/42Paris/libft)**: Custom C library functions

## Learning Resources

- **[Gitbook by Laura](https://42-cursus.gitbook.io/guide/2-rank-02/fdf)**
- **[Guide for MiniLibX by hsmits and jvan-sni](https://harm-smits.github.io/42docs/libs/minilibx.html)**
- **[Difference Between Orthographic and Isometric Projection](https://www.geeksforgeeks.org/computer-graphics/difference-between-orthographic-and-isometric-projection/)**

## AI Usage

AI was used in this project for the following tasks and parts:

- **Debugging and Troubleshooting**: AI assistance was used to identify and fix segmentation faults, particularly in memory management and pointer validation within the `fdf_clean_all` function
- **Documentation Enhancement**: AI helped structure and improve this README.md to meet 42 School requirements

**Note**: All core algorithm implementations (parsing, projection mathematics, line drawing, graphics rendering) were developed independently. AI was used only as a learning and debugging tool, not for code generation of primary functionality.

## Testing

### Manual Testing

```bash
# Test with various map files
./fdf test_maps/42.fdf
./fdf test_maps/elem.fdf
./fdf test_maps/julia.fdf
./fdf test_maps/mars.fdf

# Test MiniLibX functionality
cd mlx_linux/test && ./mlx-test
```

### Error Handling Tests

The program handles various error conditions:
- Invalid file formats
- Memory allocation failures
- Graphics library initialization failures
- File access permissions

## Technical Choices

### Graphics Pipeline
- **Image Buffer Rendering**: Uses off-screen image buffers for flicker-free rendering
- **Static Display**: Fixed projection without real-time transformation for simplicity
- **Bresenham's Algorithm**: Efficient line drawing between 2D points

### Memory Management
- **Contiguous Memory Allocation**: Points stored in single contiguous block for cache efficiency
- **Proper Cleanup**: All allocated memory properly freed in error paths
- **42 Norm Compliance**: Follows strict coding standards and memory management practices

## Future Enhancements

Potential improvements for future versions:
- Interactive controls (zoom, rotation, translation)
- Multiple projection modes (perspective, orthographic)
- Real-time color gradients based on height
- Texture mapping support
- Performance optimization for large maps
