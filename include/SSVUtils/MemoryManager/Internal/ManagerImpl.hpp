// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_MEMORYMANAGER_INTERNAL_MANAGERIMPL
#define SSVU_MEMORYMANAGER_INTERNAL_MANAGERIMPL

namespace ssvu
{
	namespace Internal
	{
		/// @brief Base memory recycler manager class.
		/// @tparam TBase Base type of manager objects.
		/// @tparam TRecycler Internal recycler type. (MonoRecycler? PolyRecycler?)
		template<typename TBase, template<typename, template<typename> class> class TRecycler> class BaseManager
		{
			template<typename T1, typename T2> friend void ssvu::eraseRemoveIf(T1&, const T2&);

			public:
				using LayoutType = LayoutImpl::LHelperBool<TBase>;
				using ChunkType = Chunk<TBase, LayoutImpl::LHelperBool>;
				using ChunkDeleterType = ChunkDeleter<TBase, LayoutImpl::LHelperBool>;
				using PtrType = UPtr<TBase, ChunkDeleterType>;
				using RecyclerType = TRecycler<TBase, LayoutImpl::LHelperBool>;
				using Container = std::vector<PtrType>;

			private:
				RecyclerType recycler;
				Container items, toAdd;

			public:
				template<typename T = TBase, typename... TArgs> inline T& create(TArgs&&... mArgs)
				{
					auto uPtr(this->recycler.template create<T>(fwd<TArgs>(mArgs)...));
					auto result(uPtr.get());
					this->toAdd.emplace_back(std::move(uPtr));
					return *reinterpret_cast<T*>(result);
				}

				inline void clear()	noexcept { items.clear(); toAdd.clear(); }
				inline void del(TBase& mBase) noexcept { LayoutType::setBool(&mBase, false); }

				inline void reserve(std::size_t mCapacity)
				{
					SSVU_ASSERT(items.capacity() < mCapacity);
					items.reserve(mCapacity);
					toAdd.reserve(mCapacity);
				}

				inline void refresh()
				{
					auto kItr(std::begin(toAdd));

					// While there currently are items in the main container...
					for(auto iItr(std::begin(items)); iItr != std::end(items); ++iItr)
					{
						// Skip alive items
						if(isAlive(iItr->get())) continue;

						// Found a dead item - possibility 1: there are no more items to add
						if(kItr == std::end(toAdd))
						{
							// Erase-remove-if all dead items from this point forward and exit
							items.erase(std::remove_if(iItr, std::end(items), [](const PtrType& mP){ return isDead(mP.get()); }), std::end(items));
							toAdd.clear();
							return;
						}

						// Found a dead item - possibility 2: there still are items to add
						*iItr = std::move(*kItr++);
					}

					// Emplace_back remaining items in the main container
					while(kItr != std::end(toAdd)) items.emplace_back(std::move(*kItr++));
					toAdd.clear();
				}

				inline static bool isAlive(const TBase* mBase) noexcept	{ return LayoutType::getBool(mBase); }
				inline static bool isDead(const TBase* mBase) noexcept	{ return !isAlive(mBase); }

				inline auto size()		const noexcept	{ return items.size(); }
				inline auto begin()		noexcept		{ return items.begin(); }
				inline auto end()		noexcept		{ return items.end(); }
				inline auto begin()		const noexcept	{ return items.begin(); }
				inline auto end()		const noexcept	{ return items.end(); }
				inline auto cbegin()	const noexcept	{ return items.cbegin(); }
				inline auto cend()		const noexcept	{ return items.cend(); }
				inline auto rbegin()	noexcept		{ return items.rbegin(); }
				inline auto rend()		noexcept		{ return items.rend(); }
				inline auto crbegin()	const noexcept	{ return items.crbegin(); }
				inline auto crend()		const noexcept	{ return items.crend(); }
		};
	}
}

#endif
