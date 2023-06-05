#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

namespace ariel
{
    MagicalContainer::MagicalContainer(){}
    MagicalContainer::MagicalContainer(std::vector<int> &vec)
    {
        _container = vec;
    }

    MagicalContainer::~MagicalContainer(){}

    void MagicalContainer::addElement(int num)
    {
        _container.push_back(num);
    }

    void MagicalContainer::removeElement(int num)
    {
        auto it = std::find(_container.begin(), _container.end(), num);
        if (it != _container.end())
        {
            _container.erase(it);
        }
        else
        {
            throw std::runtime_error("There is no suck element.");
        }
    }

    // _____________AscendingIterator_____________

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
    {
        AscendingIterator it(*_ascIt);
        it._index = _ascIt->_container.size();
        return it;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return _ascIt->_container[_index];
    }

    bool operator==(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index == lhs._index;
    }

    bool operator!=(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index != lhs._index;
    }

    bool operator>(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index > lhs._index;
    }

    bool operator<(const MagicalContainer::AscendingIterator &rhs, const MagicalContainer::AscendingIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
    {
        _index++;
        return *this;
    }

    // _____________SideCrossIterator_____________

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &other_cont) : _siCoIt(&other_cont), _index(0) {}
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){};

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
    {
        SideCrossIterator iter(*_siCoIt);
        iter._index = _siCoIt->_container.size() / 2;
        return iter;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return this->_siCoIt->_container[_index];
    }

    bool operator==(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index == lhs._index;
    }
    bool operator!=(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index != lhs._index;
    }
    bool operator>(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index > lhs._index;
    }
    bool operator<(const MagicalContainer::SideCrossIterator &rhs, const MagicalContainer::SideCrossIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        _index++;
        return *this;
    }

    // _____________PrimeIterator_____________

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other_cont) : _primIt(&other_cont), _index(0) {}
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
    {
        PrimeIterator iter(*_primIt);
        iter._index = _primIt->_container.size();
        return iter;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return _primIt->_container[_index];
    }

    bool operator==(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index == lhs._index;
    }

    bool operator!=(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index != lhs._index;
    }

    bool operator>(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index > lhs._index;
    }

    bool operator<(const MagicalContainer::PrimeIterator &rhs, const MagicalContainer::PrimeIterator &lhs)
    {
        return rhs._index < lhs._index;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        _index++;
        return *this;
    }

}
