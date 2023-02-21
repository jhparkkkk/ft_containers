/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:17:00 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/16 15:01:57 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator_traits.hpp"
namespace ft {
    template <class Iterator>
    class reverse_iterator : public std::iterator <
                typename iterator_traits<Iterator>::iterator_category,
                typename iterator_traits<Iterator>::value_type,
                typename iterator_traits<Iterator>::difference_type,
                typename iterator_traits<Iterator>::pointer,
                typename iterator_traits<Iterator>::reference>
    {
        protected:
            Iterator current;
        public:
            typedef Iterator
                iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type
                difference_type;
            typedef typename iterator_traits<Iterator>::reference
                reference;
            typedef typename iterator_traits<Iterator>::pointer
                pointer;
            typedef typename iterator_traits<Iterator>::iterator_category
                iterator_category;
            typedef typename iterator_traits<Iterator>::value_type
                value_type;
        
        /*-------------------------- Constructors ----------------------------*/
        
        // default
        reverse_iterator() : current() {/*std::cout << "reverse iterator constructor\n";*/};
        // initialization
        explicit reverse_iterator(Iterator x) : current(x) {/*std::cout << "reverse iterator explicit constructor\n";*/}
        // copy
        template <class U> reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {/*std::cout << "reverse iterator copy constructor\n";*/}
        
        /*-------------------------- Member Functions ------------------------*/

        Iterator base() const {
            return current;
        }

        reference operator*() const {
            // std::cout << "reverse iterator : operator*()\n";
            Iterator tmp = current;
            return *--tmp;
        }

        pointer operator->() const {
            // std::cout << "reverse iterator : operator->()\n";
            return &(operator*());

        }

        reverse_iterator& operator++() {
            // std::cout << "reverse iterator : operator++ pre\n";
            --current;
            return *this;
        }
        reverse_iterator operator++(int) {
            // std::cout << "reverse iterator : operator++ post\n";
            reverse_iterator tmp(*this);
            current--;
            return tmp;
        }
        reverse_iterator& operator--() {
            ++current;
            return *this;
        }
        reverse_iterator operator--(int) {
            reverse_iterator tmp(*this);
            ++current;
            return tmp;
        }
        reverse_iterator operator+ (difference_type n) const {
            return reverse_iterator(current - n);
        }
        reverse_iterator& operator+=(difference_type n) {
            current -= n;
            return *this;
        }
        reverse_iterator operator- (difference_type n) const {
            return reverse_iterator(current + n);
        }
        reverse_iterator& operator-=(difference_type n) {
            current += n;
            return *this;
        }
        reference operator[](difference_type n) const {
            return *(*this + n);
        }

        }; 

        template <class Iterator>
        bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() == y.base();
        }
        template <class Iterator>
        bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() > y.base();
        }
        template <class Iterator>
        bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() != y.base();
        }
        template <class Iterator>
        bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() < y.base();
        }
        template <class Iterator>
        bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() <= y.base();
        }
        template <class Iterator>
        bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y) {
            return x.base() >= y.base();
        }

        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type
        operator-(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y) {
            return y.base() - x.base();
        }
        template <class Iterator>
        reverse_iterator<Iterator>
        operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& x) {
            return reverse_iterator<Iterator>(x.base() - n);
        }

}
/*
----------------------------------- NOTES --------------------------------------

>>> explicit  reverse_iterator(Iterator x)
    Permet de construire un itérateur inverse à partir d'un itérateur standard.
    Ce constructeur prend en paramètre un itérateur de type Iterator et retourne
    un objet std::reverse_iterator<Iterator> qui enveloppe l'itérateur initial.
    L'itérateur inversé ainsi créé se comporte comme un itérateur qui va de la
    fin de la plage pointée par l'itérateur initial jusqu'au début de cette plage.
    Permet de parcourir les éléments de la plage dans l'ordre inverse.

    > exemple:
    std::vector<int>::iterator vector_it;
    reverse_iterator<std::vector<int>::iterator> explicit_it(vector_it);

>>> Iterator base() const
    Fonction membre qui renvoie une copie l'iterateur initial qui a été inversé.
    -> donc iterateur non inverse !

>>> Operator*()
    Dereference le reverse_iterator et retourne une reference à la valeur pointée.

>>> Operateurs de comparaison >
    Comparent 2 iterateurs inverses (de type reverse_iterator<Iterator>)
    et retourne true si le premier itérateur pointe vers un élément du conteneur
    qui est après l'élément pointé par le second itérateur.
    -> déterminer si l'ordre inverse des deux itérateurs est strictement croissant.
    -> Par ex <, x est inferieur a y si x pointe sur un element situe avant l'element
       pointe par y dans le conteneur sous-jacent. 
----------------------------------- ISSUES ------------------------------------

>>> Compilation: comparison between 2 different types of reverse_iterator
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    std::vector<double> v2;
    v2.push_back(1.0);
    v2.push_back(2.0);
    v2.push_back(3.0);
    v2.push_back(4.0);

    std::reverse_iterator<int*> ri1(&v1[0] + v1.size());
    std::reverse_iterator<double*> ri2(&v2[0] + v2.size());

    if (ri1 == ri2)
        std::cout << "CA MARCHE PAS\n";
    > Meme std::reverse_iterator ne compile pas dans ce cas je ne comprends pas pourquoi
      le template <class Iterator1, class Iterator2>
    // template <class I1, class I2>
        // bool operator==(const reverse_iterator<I1>& x, const reverse_iterator<I2>& y) {
        //     return x.base() == y.base();
        // }
    
*/