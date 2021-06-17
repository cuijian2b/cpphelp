#include <utility>

struct Callback {
    Callback() : mType(Type::Unknown),
                 mClosure(nullptr)
    {

    }
    Callback(const Callback & other) = delete;
    Callback & operator=(const Callback & other) = delete;

    void swap(Callback & other)
    {
        std::swap(mType, other.mType);
        std::swap(mClosure, other.mClosure);
    }

    enum class Type : unsigned int {
      Unknown,
      Interface,
      Function,
      Observer,        
    };
    Type mType;

    union CallbackUnion
    {
      //nsTimerCallbackFunc c;
      // These refcounted references are managed manually, as they are in a union
      //nsITimerCallback* MOZ_OWNING_REF i;
      //nsIObserver* MOZ_OWNING_REF o;
    } mCallback;

    void* mClosure;
};

