#pragma once
#include <unordered_map>
#include <functional>

template<class T, class _idx = long long, class _rank = long long>
class DSU {

	using _pair = std::pair<_idx, _rank>; // <parent, rank>

	std::unordered_map<_idx, _pair> _dsu;
	std::function<_idx(const T&)> _func;

public:

	DSU() {
		_func = [](const T& obj) { return static_cast<_idx>(obj); };
	}

	DSU(std::function<_idx(const T&)> func) {
		_func = func;
	}

	void _MakeSet(const _idx& x) {
		if (_dsu.find(x) == _dsu.end())
			_dsu[x] = _pair{ x , _rank(0) };
	}

	void MakeSet(const T& obj) {
		_MakeSet(_func(obj));
	}

	_idx _Find(const _idx& x) {
		if (_dsu.find(x) == _dsu.end()) {
			_MakeSet(x);
		}
		else if (_dsu[x].first != x) {
			_dsu[x].first = _Find(_dsu[x].first);
		}

		return _dsu[x].first;
	}

	_idx Find(const T& obj) {
		return _Find(_func(obj));
	}

	void _Union(const _idx& x, const _idx& y) {
		_idx px = _Find(x);
		_idx py = _Find(y);

		if (px == py) return;

		if (_dsu[px].second < _dsu[py].second) {
			_dsu[px].first = py;
		}
		else {
			_dsu[py].first = px;

			if (_dsu[px].second == _dsu[py].second) {
				_dsu[px].second++;
			}
		}
	}

	void Union(const T& obj1, const T& obj2) {
		_Union(_func(obj1), _func(obj2));
	}

	friend std::ostream& operator<<(std::ostream& out, const DSU<T, _idx, _rank>& dsu) {
		return out << dsu._dsu << std::endl;
	}
};