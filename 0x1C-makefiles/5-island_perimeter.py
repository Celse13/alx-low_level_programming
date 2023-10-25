#!/usr/bin/python3
"""Return the perimnter."""


def island_perimeter(grid):
    """Calculate the perimeter of the island."""
    grid_height = len(grid)
    grid_width = len(grid[0]) if grid_height else 0
    island_perimeter = 0

    for row_idx in range(grid_height):
        for col_idx in range(grid_width):
            if grid[row_idx][col_idx] == 1:
                if col_idx == 0 or grid[row_idx][col_idx-1] == 0:
                    island_perimeter += 1
                if col_idx == grid_width - 1 or grid[row_idx][col_idx+1] == 0:
                    island_perimeter += 1
                if row_idx == 0 or grid[row_idx-1][col_idx] == 0:
                    island_perimeter += 1
                if row_idx == grid_height - 1 or grid[row_idx+1][col_idx] == 0:
                    island_perimeter += 1

    return island_perimeter
