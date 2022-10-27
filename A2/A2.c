/**
 * -------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student email: vanv2490@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"
# include <string.h>

//----------- Task 1: Matrix Checkers ------------

int _is_square() {
	//implementing this private helper function is optional
	int square = 1, i = 0, j = 0, col = 0, row = 0;

	if (is_matrix() == 0)
		return square = 0;

	row = get_row_length(1);
	col = get_column_length(1);

	for (i = 0; i < row; i++) {
		for (j = 0; j < SIZE; j++) {
			if (get_element(i, j) == -1) {
				if (col != j) {
					square = 0;
					break;
				} else
					break;
			}
		}
	}
	if (row != col)
		square = 0;

	return square;
}
/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements are equal to 0
 * 		An empty matrix is NOT an identity matrix
 * ----------------------------------------------------------------
 */
int is_identity() {
	int identity = 1, i = 0, j = 0;

	if (is_matrix() == 0)
		return identity = 0;

	if (is_empty())
		return identity = 0;

	if (_is_square() == 0) {
		;
		return identity = 0;
	}
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (get_element(i, j) == -1)
				break;
			if (j == i && get_element(i, j) != 1) {
				return identity = 0;
			}
			if (i != j && get_element(i, j) != 0) {
				return identity = 0;
			}
		}
	}
	return identity;
}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		An empty matrix is NOT a unique matrix
 * ----------------------------------------------------------------
 */
int is_unique() {
	int unique = 1, i = 0, j = 0, k = 0, l = 0, value;

	if (is_matrix() == 0)
		return unique = 0;

	if (is_empty())
		return unique = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			value = get_element(i, j);
			if (value != -1) {
				for (k = 0; k < SIZE; k++) {
					for (l = 0; l < SIZE; l++) {
						if ((k != i || l != j) && value == get_element(k, l)) {
							return unique = 0;
						}
					}
				}
			} else
				break;
		}
	}

	return unique;
}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		An empty matrix is NOT a uniform matrix
 * ----------------------------------------------------------------
 */
int is_uniform() {
	int uniform = 1, value, i = 0, j = 0;

	if (is_matrix() == 0)
		return uniform = 0;

	if (is_empty())
		return uniform = 0;

	value = get_element(0, 0);

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (get_element(i, j) == -1)
				break;
			if (get_element(i, j) != value)
				return uniform = 0;
		}

	}

	return uniform;
}

//----------- Task 2: Matrix Classifier ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		mode(char): s = size, c = content
 * return:			type(int)
 * Description:
 * 		inspect the current contents of matrix
 * 		Returns the classification of the matrix
 * 		General classification (works for both modes):
 * 			-1: not matrix
 * 			 0: empty matrix
 * 		Matrix classification by size:
 * 			 1: vector
 * 			 2: square
 * 			 3: rectangle
 * 		Matrix classification by content:
 * 			 1: identity
 * 			 2: unique
 * 			 3: uniform
 * 			 4: undefined
 * Errors:	 		invalid mode
 * ----------------------------------------------------------------
 */
int classify_matrix(char mode) {
	int classify;

	if (is_matrix() == 0)
		return classify = -1;

	if (is_empty())
		return classify = 0;

	if (mode == 's') {
		if (is_vector() == 1)
			return 1;
		else if (_is_square() == 1)
			return 2;
		else
			return 3;
	}

	else if (mode == 'c') {
		if (is_identity() == 1)
			return 1;
		else if (is_unique() == 1)
			return 2;
		else if (is_uniform() == 1)
			return 3;
		else
			return 4;
	} else
		return 5;
	return 0;
}

/**
 * ----------------------------------------------------------------
 * Parameters:	no parameters
 * return:		no returns
 * Description:
 * 		prints classification of the matrix based on current values
 * 		classification includes both size and content
 * 		see sample output for format
 * Errors:	 	invalid mode
 * ----------------------------------------------------------------
 */
void print_matrix_classification() {
	char type1[20];
	char type2[20];
	int size, content;

	size = classify_matrix('s');
	content = classify_matrix('c');

	if ((size == -1) || (content == -1)) {
		printf("invalid matrix\n");
		return;
	}
	if ((size || content) == 0) {
		printf("empty matrix\n");
		return;
	}
	switch (size) {
	case 1:
		strcpy(type1, "vector");
		break;
	case 2:
		strcpy(type1, "square");
		break;
	case 3:
		strcpy(type1, "rectangle");
		break;
	default:
		printf("EROORRRR");
	}
	switch (content) {
	case 1:
		strcpy(type2, "identity");
		break;
	case 2:
		strcpy(type2, "unique");
		break;
	case 3:
		strcpy(type2, "uniform");
		break;
	case 4:
		strcpy(type2, "undefined");
		break;
	default:
		printf("23ERORROROR");
	}
	printf("%s %s matrix\n", type2, type1);
	return;
}

//----------- Task 3: Triangular Matrix  ------------

/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void fill_triangle(int length, char corner, char side, int fill) {
	int i, j;
	if ((corner != 'T') && (corner != 'B')) {
		printf("Error(fill_triangle): invalid corner\n");
		return;
	}
	if ((side != 'R') && (side != 'L')) {
		printf("Error(fill_triangle): invalid side\n");
		return;
	}
	if (length > SIZE || length < 1) {
		printf("Error(fill_triangle): invalid length\n");
		return;
	}

	if (corner == 'T' && side == 'L') {
		for (i = 0; i < length; i++) {
			for (j = 0; j < length; j++) {
				set_element(i, j - i, fill);
				if (get_element(i, j) != fill)
					set_element(i, j, 0);
			}
		}
	}

	else if (corner == 'T' && side == 'R') {
		for (i = 0; i < length; i++) {
			for (j = 0; j < length; j++) {
				if (j < i)
					set_element(i, j, 0);
				else
					set_element(i, j, fill);
			}
		}
	}

	else if (corner == 'B' && side == 'L') {
		for (i = 0; i < length; i++) {
			for (j = 0; j < length; j++) {
				if (j <= i)
					set_element(i, j, fill);
				else
					set_element(i, j, 0);
			}
		}
	}

	else if (corner == 'B' && side == 'R') {
		for (i = 0; i < length; i++) {
			for (j = 0; j < length; j++) {
				if ((j + i) >= length - 1)
					set_element(i, j, fill);
				else
					set_element(i, j, 0);
			}
		}
	}
	return;
}

//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */
void flip(char mode) {
	int i, j, length, temp, length2;

	if (is_matrix() == 0) {
		printf("Error(flip): invalid matrix\n");
		return;
	}
	if (mode != 'h' && mode != 'v') {
		printf("Error(flip): invalid mode\n");
		return;
	}
	if (mode == 'v') {
		if (is_vector() != 1) {
			length = get_row_length(0);
			for (i = 0; i < length; i++) {
				for (j = 0; j < length / 2; j++) {
					temp = get_element(i, j);
					set_element(i, j, get_element(i, length - j - 1));
					set_element(i, length - j - 1, temp);
				}
			}
		} else if (is_vector() == 1) {
			length = get_row_length(0);
			length2 = get_column_length(0);
			if (length > length2) {
				for (j = 0; j < length / 2; j++) {
					temp = get_element(0, j);
					set_element(0, j, get_element(0, length - j - 1));
					set_element(0, length - j - 1, temp);

				}
			}
		}
	}
	if (mode == 'h') {
		if (is_vector() != 1) {
			length = get_row_length(0);
			for (i = 0; i < length / 2; i++) {
				for (j = 0; j < length; j++) {
					temp = get_element(i, j);
					set_element(i, j, get_element(length - i - 1, j));
					set_element(length - i - 1, j, temp);
				}
			}
		} else if (is_vector() == 1) {
			length = get_row_length(0);
			length2 = get_column_length(0);
			if (length2 > length) {
				for (i = 0; i < length2 / 2; i++) {
					temp = get_element(i, 0);
					set_element(i, 0, get_element(length2 - 1 - i, 0));
					set_element(length2 - i - 1, 0, temp);
				}
			}
		}
	}
	return;
}

