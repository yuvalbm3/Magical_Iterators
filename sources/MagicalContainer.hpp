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
        std::string _name;
        std::vector<int> getCont()
        {
            return _container;
        }

    public:
        MagicalContainer();
        MagicalContainer(std::vector<int> &);
        ~MagicalContainer();
        void addElement(int);
        void removeElement(int);
        int size();

        class AscendingIterator
        {
        private:
            MagicalContainer& _ascIt;
            int _size;

        public:
            AscendingIterator(MagicalContainer&);
            ~AscendingIterator();
            int size();
            AscendingIterator begin();
            AscendingIterator end();

            int operator*() const;
            friend bool operator==(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator!=(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator>(const AscendingIterator& rhs, const AscendingIterator& lhs);
            friend bool operator<(const AscendingIterator& rhs, const AscendingIterator& lhs);
            AscendingIterator& operator++();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer& _siCoIt;
            int _size;

        public:
            SideCrossIterator(MagicalContainer &other_cont);
            ~SideCrossIterator();
            int size();
            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            int operator*() const;
            friend bool operator==(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator!=(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator>(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            friend bool operator<(const SideCrossIterator& rhs, const SideCrossIterator& lhs);
            SideCrossIterator& operator++();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer& _primIt;
            int _size;

        public:
            PrimeIterator(MagicalContainer &other_cont);
            ~PrimeIterator();

            int size();
            PrimeIterator begin() const;
            PrimeIterator end() const;
            
            int operator*() const;
            friend bool operator==(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator!=(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator>(const PrimeIterator& rhs, const PrimeIterator& lhs);
            friend bool operator<(const PrimeIterator& rhs, const PrimeIterator& lhs);
            PrimeIterator& operator++();
        };
    };

}

#endif
