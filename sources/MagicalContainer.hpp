#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

#include <vector>
#include <string>
#include <math.h>
#include <iterator>
#include <cstddef>
#include <algorithm> // Added for std::sort

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> _container;

    public:
        MagicalContainer();
        MagicalContainer(std::vector<int> &);
        ~MagicalContainer();
        void addElement(int);
        void removeElement(int);
        int size() const{
            return (int)this->_container.size();
        }

        class AscendingIterator
        {
        private:
            MagicalContainer* _ascIt;
            // int _size;
            std::vector<int>::size_type _index;

        public:
            AscendingIterator(MagicalContainer &container) : _ascIt(&container), _index(0) {
                std::sort(_ascIt->_container.begin(), _ascIt->_container.end());
            }
            AscendingIterator(const AscendingIterator &other) : _ascIt(other._ascIt), _index(other._index) {};
            AscendingIterator() : _ascIt(nullptr), _index(0) {};
            ~AscendingIterator() {}
            // int size();
            AscendingIterator begin() const;
            AscendingIterator end() const;
            
            size_t get_index(){
                return _index;
            }

            //move assignment operator
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            //move constructor
            AscendingIterator(AscendingIterator&& other) noexcept : _ascIt(other._ascIt), _index(0) {}

            AscendingIterator& operator=(const AscendingIterator &other);

            int operator*();
            friend bool operator==(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator!=(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator>(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator<(const AscendingIterator& rhs, const AscendingIterator& lhs);
            AscendingIterator operator++();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer* _siCoIt;
            std::vector<int>::size_type _index;

        public:
            SideCrossIterator(MagicalContainer &other_cont);
            ~SideCrossIterator();
            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            size_t get_index(){
                return _index;
            }

            int operator*();
            friend bool operator==(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator!=(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator>(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator<(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            SideCrossIterator& operator++();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer* _primIt;
            std::vector<int>::size_type _index;

        public:
            PrimeIterator(MagicalContainer &other_cont);
            ~PrimeIterator();

            PrimeIterator begin() const;
            PrimeIterator end() const;
            
            size_t get_index(){
                return _index;
            }

            int operator*();
            friend bool operator==(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator!=(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator>(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator<(const PrimeIterator& rhs, const PrimeIterator& lhs);
            PrimeIterator& operator++();
        };
    };

}

#endif
