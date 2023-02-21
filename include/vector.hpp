/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:16:39 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/21 14:34:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <memory>
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"

#include <iterator>

namespace ft {
    template <class T, class Allocator = std::allocator<T> >
    class vector {

    public:
    // types:
        typedef typename Allocator::reference       reference;
        typedef typename Allocator::const_reference const_reference;
        // typedef implementation defined size_type; // See 23.1
        // typedef implementation defined difference_type;// See 23.1
        typedef T                                   value_type;
        typedef Allocator                           allocator_type; // alias for the Allocator
        typedef typename Allocator::pointer         pointer;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef size_t                              size_type;
        // typedef implementation defined iterator; // See 23.1
        // typedef implementation defined const_iterator; // See 23.1
        // typedef reverse_iterator<iterator> reverse_iterator;
        // typedef reverse_iterator<const_iterator> const_reverse_iterator;
    private:
        allocator_type  _alloc;
        pointer         _c;
        pointer         _begin;
        pointer         _end;
        size_type       _size;
        size_type       _capacity;
    public:

    // construct/copy/destroy:
    explicit vector(const Allocator& alloc = Allocator()) :
    _alloc(alloc),
    _c(0),
    _size(0),
    _capacity(0)
    {
        std::cout << "empty constructor\n";
    }

    explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator()) :
    _alloc(),
    _c(_alloc.allocate(n)),
    _begin(_c),
    _end(_c + n),
    _size(n),
    _capacity(n)
    {
        std::cout << "n = " << n << "\n";
        std::cout << "value = " << value << "\n";
        std::cout << "_c is located at: " << _c << "\n";
        std::cout << "_begin is located at: " << _begin << "\n";
        std::cout << "_end is located at: " << _end << "\n";

        for (size_type i=0; i<n; i++)
            _c[i] = value;
            // _alloc.construct(_c[i], value);
        std::cout << "fill constructor\n";
    }
    
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, const Allocator& = Allocator());
    
    // vector(const vector<T,Allocator>& x);
    
    ~vector() { std::cout << "destructor\n";}

    // vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
    //     this->_c = x;
    //     return *this;
    // }

    
    
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last);
    
    // void assign(size_type n, const T& u);
    
    // allocator_type get_allocator() const;
    
    // // iterators:
    // iterator begin();
    // const_iterator begin() const;
    // iterator end();
    // const_iterator end() const;
    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;
    
    // // capacity:
    size_type size() const
        { return _size; }
    // size_type max_size() const;
    // void resize(size_type sz, T c = T());
    // size_type capacity() const;
    // bool empty() const;
    // void reserve(size_type n);
    
    // // element access:
    // reference operator[](size_type n);
    // const_reference operator[](size_type n) const;
    // const_reference at(size_type n) const;
    // reference at(size_type n);
    reference front()
        { return *_begin; }
    const_reference front() const
        { return *_begin; }
    reference back()
        { return *(_end - 1); }
    const_reference back() const
        { return *(_end - 1); }
    
    // // 23.2.4.3 modifiers:
    //  void push_back(const T& value) {
    //     if (m_size >= m_capacity) {
    //         // Si le tableau est plein, allouer un nouvel espace de mémoire
    //         size_t new_capacity = (m_capacity == 0 ? 1 : m_capacity * 2);
    //         T* new_data = m_allocator.allocate(new_capacity);

    //         // Copier les anciens éléments dans le nouvel espace de mémoire
    //         for (size_t i = 0; i < m_size; ++i) {
    //             m_allocator.construct(&new_data[i], m_data[i]);
    //             m_allocator.destroy(&m_data[i]);
    //         }

    //         // Libérer l'ancien espace de mémoire
    //         m_allocator.deallocate(m_data, m_capacity);

    //         // Mettre à jour les variables de membre pour utiliser le nouvel espace de mémoire
    //         m_data = new_data;
    //         m_capacity = new_capacity;
    //     }

    //     // Ajouter le nouvel élément à la fin du tableau
    //     m_allocator.construct(&m_data[m_size], value);
    //     ++m_size;
    // }
    void push_back(const T& x) {
        // if container is full then allocate a new container
        if (_size >= _capacity) {
            size_t new_capacity = (_capacity == 0 ? 1 : _capacity * 2);
            T* new_c = _alloc.allocate(new_capacity);
            // copy elements from _c to new_c
            for (size_t i = 0; i < _size; ++i) {
                new_c[i] = _c[i];
                _alloc.destroy(&_c[i]);
            }
            // free old _c
            _alloc.deallocate(_c, _capacity);
            // update member variables to use new container
            _c = new_c;
            _capacity = new_capacity;
        }
        std::cout << "size is: " << _size;
        std::cout << "capacity is: " << _capacity;

        _size++;
        _c[_size-1] = x;
        _begin = _c;

    }
    // void pop_back();
    // iterator insert(iterator position, const T& x);
    // void insert(iterator position, size_type n, const T& x);
    // template <class InputIterator>
    // void insert(iterator position,
    // InputIterator first, InputIterator last);
    // iterator erase(iterator position);
    // iterator erase(iterator first, iterator last);
    // void swap(vector<T,Allocator>&);
    // void clear();
    // };
    
    // template <class T, class Allocator>
    // bool operator==(const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    // template <class T, class Allocator>
    // bool operator< (const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    // template <class T, class Allocator>
    // bool operator!=(const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    // template <class T, class Allocator>
    // bool operator> (const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    // template <class T, class Allocator>
    // bool operator>=(const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    // template <class T, class Allocator>
    // bool operator<=(const vector<T,Allocator>& x,
    // const vector<T,Allocator>& y);
    
    // // specialized algorithms:
    // template <class T, class Allocator>
    // void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
    };
}

/*
----------------------------------- NOTES --------------------------------------
>>> members _c and _begin
    Do I need 2 disctinct pointers ?
>>> Constructors
    (1) empty: no elements.
    (2) fill: with n elements. Each element is a copy of val.  
>>> allocator_type
    whatever type Allocator is, it gets a type alias in form of allocator_type.
    They mean the same thing but Allocator is only visible to members of the class,
    so the alias is required to make it public.

----------------------------------- ISSUES ------------------------------------
>>> Constructor fill
    segf when assigning value
    > maybe cause assigning method not implemented yet...
*/