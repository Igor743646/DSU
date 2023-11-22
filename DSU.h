#pragma once
#include <iostream>
#include <unordered_map>
#include <functional>

template<class T>
class TDsu {

	using TIndex = size_t;
	using TRank = size_t;

	struct TData {
		TIndex Parent;
		TRank Rank;
	};

	using TContainer = std::unordered_map<TIndex, TData>;
	using TFunc = std::function<TIndex(const T&)>;

public:

	TDsu() {
		Func = [](const T& obj) { return static_cast<TIndex>(obj); };
	}

	TDsu(TFunc func) {
		Func = func;
	}

	void MakeSet(const T& obj) {
		_MakeSet(Func(obj));
	}

	TIndex Find(const T& obj) {
		return _Find(Func(obj));
	}

	void Union(const T& obj1, const T& obj2) {
		_Union(Func(obj1), Func(obj2));
	}

private:

	void _MakeSet(const TIndex& x) {
		if (Dsu.find(x) == Dsu.end())
			Dsu[x] = TData{ x , TRank(0) };
	}

	TIndex _Find(const TIndex& x) {
		if (Dsu.find(x) == Dsu.end()) {
			_MakeSet(x);
		}
		else if (Dsu[x].Parent != x) {
			Dsu[x].Parent = _Find(Dsu[x].Parent);
		}

		return Dsu[x].Parent;
	}

	void _Union(const TIndex& x, const TIndex& y) {
		TIndex px = _Find(x);
		TIndex py = _Find(y);

		if (px == py) return;

		if (Dsu[px].Rank < Dsu[py].Rank) {
			Dsu[px].Parent = py;
		}
		else {
			Dsu[py].Parent = px;

			if (Dsu[px].Rank == Dsu[py].Rank) {
				Dsu[px].Rank++;
			}
		}
	}

private:

	TContainer Dsu;
	TFunc Func;

};
