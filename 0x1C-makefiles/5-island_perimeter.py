#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): Represents the island where:
                                    0 represents a water zone
                                    1 represents a land zone

    Returns:
        int: Perimeter of the island

    Example:
        Input: grid = [[0,1,0,0],
                       [1,1,1,0],
                       [0,1,0,0],
                       [1,1,0,0]]
        Output: 16

        Explanation: Perimeter is 16 cause there are 16 edges around island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
