#pragma once
template <typename T>
class Matrix {
private:
	T** matrix;
	size_t m_number_of_rows;
	size_t m_number_of_columns;

	// will inialize all with default constructor, so 0/1 for RationalNum
	void allocate() {
		matrix = new T * [m_number_of_rows];
		for (size_t i = 0; i < m_number_of_rows; i++) {
			matrix[i] = new T[m_number_of_columns];
		}
	}

	// doens't change m_number_of_rows, m_number_of_columns
	void deallocate() {
		for (size_t i = 0; i < m_number_of_rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
public:
	size_t get_number_of_rows() const {
		return m_number_of_rows;
	}

	size_t get_number_of_columns() const {
		return m_number_of_columns;
	}

	T*& operator[](size_t index) {
		if (index >= m_number_of_rows) throw "Matrix: Index out of range!";
		return matrix[index];
	}

	const T*& operator[](size_t index) const {
		if (index >= m_number_of_rows) throw "Matrix: Index out of range!";
		return (const T*&) matrix[index];
	}

	Matrix()
		: m_number_of_rows(0), m_number_of_columns(0)
	{
		matrix = nullptr;
	}
	// will inialize all with default constructor, so 0/1 for RationalNum
	Matrix(size_t number_of_rows, size_t number_of_columns)
		: m_number_of_rows(number_of_rows), m_number_of_columns(number_of_columns)
	{
		allocate();
	}

	~Matrix() {
		deallocate();
	}

	// will inialize all with default constructor, so 0/1 for RationalNum and fill with contents of old matrix where possible
	void expand(size_t new_number_of_rows, size_t new_number_of_columns) {
		// allocate new matrix
		T** new_matrix = new T*[new_number_of_rows];
		for (size_t i = 0; i < new_number_of_rows; i++) {
			new_matrix[i] = new T[new_number_of_columns];
		}
		for (size_t i = 0; i < m_number_of_rows; i++) {
			for (size_t j = 0; j < m_number_of_columns; j++) {
				new_matrix[i][j] = matrix[i][j];
			}
		}
		deallocate();
		// assign new values
		matrix = new_matrix;
		m_number_of_rows = new_number_of_rows;
		m_number_of_columns = new_number_of_columns;
	}

	// copy constructor
	Matrix(const Matrix<T>& other) 
		: m_number_of_rows(other.m_number_of_rows), m_number_of_columns(other.m_number_of_columns)
	{
		allocate();

		for (size_t i = 0; i < m_number_of_rows; i++) {
			for (size_t j = 0; j < m_number_of_columns; j++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}

	// copy assignment operator
	Matrix<T>& operator=(const Matrix<T>& other) {
		if (this != &other) {
			if (!(m_number_of_rows == other.m_number_of_rows && m_number_of_columns == other.m_number_of_columns)) {
				deallocate();
				m_number_of_rows = other.m_number_of_rows;
				m_number_of_columns = other.m_number_of_columns;
				allocate();
			}
			for (size_t i = 0; i < m_number_of_rows; i++) {
				for (size_t j = 0; j < m_number_of_columns; j++) {
					matrix[i][j] = other.matrix[i][j];
				}
			}
		}
		return *this;
	}

	// move constructor
	Matrix(Matrix<T>&& other) noexcept 
		: m_number_of_rows(other.m_number_of_rows), m_number_of_columns(other.m_number_of_columns)
	{
		matrix = other.matrix;
		other.m_number_of_rows = 0;
		other.m_number_of_columns = 0;
		other.matrix = nullptr;
	}

	//move assignment operator
	Matrix<T>& operator=(Matrix<T>&& other) noexcept {
		if (this != &other) {
			deallocate();
			m_number_of_rows = other.m_number_of_rows;
			m_number_of_columns = other.m_number_of_columns;
			matrix = other.matrix;
			other.m_number_of_rows = 0;
			other.m_number_of_columns = 0;
			other.matrix = nullptr;
		}
		return *this;
	}

	// Addition of two matrices O(n^2)
	friend Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right) {
		if (!(left.get_number_of_rows() == right.get_number_of_rows() && left.get_number_of_columns() == right.get_number_of_columns())) {
			throw "Matrix + : matricies must have equal dimensions";
		}
		size_t number_of_rows = left.get_number_of_rows(), number_of_columns = left.get_number_of_columns();
		Matrix result(number_of_rows, number_of_columns);
		for (size_t i = 0; i < number_of_rows; i++) {
			for (size_t j = 0; j < number_of_columns; j++) {
				result[i][j] = left[i][j] + right[i][j];
			}
		}
		return result;
	}

	// Subtraction of two matrices O(n^2)
	friend Matrix<T> operator-(const Matrix<T>& left, const Matrix<T>& right) {
		if (!(left.get_number_of_rows() == right.get_number_of_rows() && left.get_number_of_columns() == right.get_number_of_columns())) {
			throw "Matrix - : matricies must have equal dimensions";
		}
		size_t number_of_rows = left.get_number_of_rows(), number_of_columns = left.get_number_of_columns();
		Matrix result(number_of_rows, number_of_columns);
		for (size_t i = 0; i < number_of_rows; i++) {
			for (size_t j = 0; j < number_of_columns; j++) {
				result[i][j] = left[i][j] - right[i][j];
			}
		}
		return result;
	}

	// Equality of matrices O(n^2)
	friend bool operator==(const Matrix<T>& left, const Matrix<T>& right) {
		if (!(left.get_number_of_rows() == right.get_number_of_rows() && left.get_number_of_columns() == right.get_number_of_columns())) {
			return false;
		}
		size_t number_of_rows = left.get_number_of_rows(), number_of_columns = left.get_number_of_columns();
		for (size_t i = 0; i < number_of_rows; i++) {
			for (size_t j = 0; j < number_of_columns; j++) {
				if (left[i][j] != right[i][j]) return false;
			}
		}
		return true;
	}

	friend bool operator!=(const Matrix<T>& left, const Matrix<T>& right) {
		return !(left == right);
	}

	// Scalar Multiplication O(n^2)
	friend Matrix<T> operator*(const T& left, const Matrix<T>& right) {
		size_t number_of_rows = right.get_number_of_rows(), number_of_columns = right.get_number_of_columns();
		Matrix result(number_of_rows, number_of_columns);
		for (size_t i = 0; i < number_of_rows; i++) {
			for (size_t j = 0; j < number_of_columns; j++) {
				result[i][j] = left * right[i][j];
			}
		}
		return result;
	}
};