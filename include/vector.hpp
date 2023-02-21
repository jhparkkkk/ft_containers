/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:16:39 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/21 13:57:22 by jeepark          ###   ########.fr       */
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
    public:

    // construct/copy/destroy:
    explicit vector(const Allocator&  = Allocator()) : _alloc() {
        std::cout << "empty constructor\n";
    };
    
    explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator())  {
        (void) n;
        (void) value;
        std::cout << "n = " << n << "\n";
        std::cout << "value = " << value << "\n";

        _alloc.allocate(n);
        // std::cout << "allocator value" << _c[0] << "\n;";
        // _alloc.construct(_c, value);
        _c[0] = 1;
        // _c[0] = value;
        // for (size_t i=0; i < n; i++)
        //     _c[i] = value;
        
        std::cout << "fill constructor\n";
    };
    
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, const Allocator& = Allocator());
    
    // vector(const vector<T,Allocator>& x);
    
    ~vector() { std::cout << "destructor\n";};

    vector<T,Allocator>& operator=(const vector<T,Allocator>& x) {
        this->_c = x;
        return *this;
    }

    };
    
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
    // size_type size() const;
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
    // reference front();
    // const_reference front() const;
    // reference back();
    // const_reference back() const;
    
    // // 23.2.4.3 modifiers:
    // void push_back(const T& x);
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
}

/*
----------------------------------- NOTES --------------------------------------
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