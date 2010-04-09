/** 
 * @file matrix.hpp
 * @brief general base class for 2D matrices
 * @ingroup basics
 * @author Hannes Schulz
 * @date 2010-03-21
 */
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cuv_general.hpp>

namespace cuv{

	template<class V, class T, class I>
	class dia_matrix;
		
	//template<class __value_type, class __index_type>
	//class dev_vector;

	//template<class __value_type, class __index_type>
	//class host_vector;

	//struct memory_layout_tag{};
	//struct column_major : public memory_layout_tag{}; ///< Trait for column major matrices
	//struct row_major    : public memory_layout_tag{}; ///< Trait for row major matrices
	
	//template<class __value_type,class __index_type>
	//struct matrix_traits<__value_type, __index_type,dev_memory_space> {
		//typedef dev_vector<__value_type, __index_type>  vector_type;
	//};

	//template<class __value_type,class __index_type>
	//struct matrix_traits<__value_type, __index_type,host_memory_space> {
		//typedef host_vector<__value_type, __index_type>  vector_type;
	//};

/**
 * @brief Basic matrix class
 *
 * This matrix class is the parent of all other matrix classes and has all the basic attributes that all matrices share.
 * This class is never actually instanciated.
 */
template<class __value_type, class __index_type>
class matrix
	{
	  public:
		  typedef __value_type value_type;	///< Type of the entries of matrix
		  typedef __index_type index_type;	///< Type of indices
		  template <class Archive, class V, class I> friend void serialize(Archive&, dia_matrix<V,host_memory_space, I>&, unsigned int) ; ///< serialization function to save matrix
	  protected:
		  index_type m_width; ///< Width of matrix
		  index_type m_height; ///< Heigth of matrix
		public:
		  /** 
		   * @brief Basic constructor: set width and height of matrix but do not allocate any memory
		   * 
		   * @param h Height of matrix
		   * @param w Width of matrix
		   */
		  matrix(const index_type& h, const index_type& w) 
			: m_width(w), m_height(h)
			{
			}
		  virtual ~matrix(){ ///< Destructor calls dealloc.
			  dealloc();
		  }
		  /** 
		   * @brief Resizing matrix: changing width and height without changing memory layout
		   * 
		   * @param h New height of matrix 
		   * @param w New width of matrix
		   */
		  inline void resize(const index_type& h, const index_type& w) 
		  {
			  m_width=w;
			  m_height=h;
		  }
		  inline index_type w()const  { return m_width;                } ///< Return matrix width
		  inline index_type h()const  { return m_height;               } ///< Return matrix height
		  inline index_type n()const  { return w()*h();                } ///< Return number of entries in matrix
		  virtual void alloc() {}; ///< Does nothing
		  virtual void dealloc() {}; ///< Does nothing
	};
}

#endif /* __MATRIX_HPP__ */
