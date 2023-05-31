#include "MagicalContainer.hpp"

#include <vector>
#include <string>
#include <math.h>
#include <algorithm> // Added for std::sort
#include <algorithm>

using namespace std;

// namespace ariel
// {
//     MagicalContainer::MagicalContainer(std::vector<int> &new_cont)
//     {
//         this->_container = new_cont;
//     }

//     MagicalContainer::~MagicalContainer()
//     {
//     }

//     void MagicalContainer::addElement(int elem)
//     {
//         _container.push_back(elem);
//     }

//     void MagicalContainer::removeElement(int elem)
//     {
//         for (int num : _container)
//         {
//             if (elem == num)
//             {
//                 _container.erase(std::remove(_container.begin(), _container.end(), elem), _container.end());
//             }
//         }
//     }

//     int MagicalContainer::size()
//     {
//         return _container.size();
//     }

// }

namespace ariel
{
    MagicalContainer::MagicalContainer()
    {
    }
    MagicalContainer::MagicalContainer(std::vector<int> &)
    {
    }
    MagicalContainer::~MagicalContainer()
    {
    }
    void MagicalContainer::addElement(int)
    {
    }
    void MagicalContainer::removeElement(int)
    {
    }
    int MagicalContainer::size()
    {
        return this->_container.size();
    }

    // _____________AscendingIterator_____________

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : _ascIt(container), _size(0) {}
    // MagicalContainer::AscendingIterator(MagicalContainer& other_cont):_ascIt(other_cont), _size(0){}
    MagicalContainer::AscendingIterator::~AscendingIterator() {}
    int MagicalContainer::AscendingIterator::size()
    {
        return _size;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator iter(this->_ascIt);
        iter._size = 0;
        return iter;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator iter(this->_ascIt);
        iter._size = _ascIt.size();
        return iter;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        // return (this)->_ascIt.ascending[_size];
        return 0;
    }

    bool operator==(const MagicalContainer::AscendingIterator& first, const MagicalContainer::AscendingIterator& second) {
        return true;
    }
    
    bool operator!=(const MagicalContainer::AscendingIterator& first, const MagicalContainer::AscendingIterator& second) {
        return true;
    }
    
    bool operator>(const MagicalContainer::AscendingIterator& first, const MagicalContainer::AscendingIterator& second) {
        return true;
    }
    
    bool operator<(const MagicalContainer::AscendingIterator& first, const MagicalContainer::AscendingIterator& second) {
        return true;
    }
    
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }


    // _____________SideCrossIterator_____________

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &other_cont) : _siCoIt(other_cont), _size(0)
    {
        // _size = other_cont.size();
        // std::vector<int> sorted = other_cont.getCont();
        // std::sort(sorted.begin(), sorted.end()); // Sort the vector
        // for (int i = 0; i < floor(_size / 2); i++)
        // {
        //     _siCoIt.push_back(sorted[i]);
        //     _siCoIt.push_back(sorted[_size - i]);
        // }
    }
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){};

    int MagicalContainer::SideCrossIterator::size()
    {
        return this->_size;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        SideCrossIterator iter(this->_siCoIt);
        iter._size = 0;
        return iter;
    }
    
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        SideCrossIterator iter(this->_siCoIt);
        iter._size = _siCoIt.size();
        return iter;
    }
    
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return true;
    }

    bool operator==(const MagicalContainer::SideCrossIterator& first, const MagicalContainer::SideCrossIterator& second) {
        return true;
    }
    bool operator!=(const MagicalContainer::SideCrossIterator& first, const MagicalContainer::SideCrossIterator& second) {
        return true;
    }
    bool operator>(const MagicalContainer::SideCrossIterator& first, const MagicalContainer::SideCrossIterator& second) {
        return true;
    }
    bool operator<(const MagicalContainer::SideCrossIterator& first, const MagicalContainer::SideCrossIterator& second) {
        return true;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }



    // _____________PrimeIterator_____________

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other_cont) : _primIt(other_cont), _size(0)
    {
        // _size = other_cont.size();
        // _primIt = other_cont.getCont();
        // for (int num : _primIt)
        // {
        //     if (num == 2)
        //     {
        //         continue;
        //     }
        //     else if (num > 2 && num % 2 == 1)
        //     {
        //         for (size_t i = 2; i < sqrt(num); i = i + 2)
        //         {
        //             if (num % i == 0)
        //             {
        //                 _primIt.erase(std::remove(_primIt.begin(), _primIt.end(), num), _primIt.end());
        //                 _size--;
        //             }
        //         }
        //     }
        // }
        // std::sort(_primIt.begin(), _primIt.end()); // Sort the vector
    }
    MagicalContainer::PrimeIterator::~PrimeIterator() {}
    int MagicalContainer::PrimeIterator::size()
    {
        return _size;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        PrimeIterator iter(this->_primIt);
        iter._size = 0;
        return iter;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
    {
        PrimeIterator iter(this->_primIt);
        iter._size = _primIt.size();
        return iter;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return true;
    }

    bool operator==(const MagicalContainer::PrimeIterator& first, const MagicalContainer::PrimeIterator& second){return true;}
    bool operator!=(const MagicalContainer::PrimeIterator& first, const MagicalContainer::PrimeIterator& second){return true;}
    bool operator>(const MagicalContainer::PrimeIterator& first, const MagicalContainer::PrimeIterator& second){return true;}
    bool operator<(const MagicalContainer::PrimeIterator& first, const MagicalContainer::PrimeIterator& second){return true;}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){return *this;}

}
