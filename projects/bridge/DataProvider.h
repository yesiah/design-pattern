#include <string>

class DataProvider {
public:
    /// dummy iterator
    struct Iterator {
        Iterator(std::string value) : value(value) {}

        std::string Value() const {
            return value;
        }
    
    private:
        std::string value;
    };

    virtual ~DataProvider() {};

    virtual Iterator GetFirst() const = 0;
    virtual bool HasMore() const = 0;
    virtual Iterator GetNext() const = 0;
    virtual Iterator GetNth() const = 0;
};

///
/// Database Implementation
///
// class SQLServer : public DataProvider {
//     virtual Iterator GetFirst() const override {
//         return {};
//     }

//     virtual bool HasMore() const override {
//         return false;
//     }

//     virtual Iterator GetNext() const override {
//         return {};
//     }

//     virtual Iterator GetNth() const override {
//         return {};
//     }
// };

///
/// Local Database Implementation
///
class LevelDb : public DataProvider {
    virtual Iterator GetFirst() const override {
        return {"LevelDb"};
    }

    virtual bool HasMore() const override {
        return false;
    }

    virtual Iterator GetNext() const override {
        return {"LevelDb"};
    }

    virtual Iterator GetNth() const override {
        return {"LevelDb"};
    }
};

///
/// Textfile Implementation
///
// class Csv : public DataProvider {
//     virtual Iterator GetFirst() const override {

//         return {};
//     }

//     virtual bool HasMore() const override {
//         return false;
//     }

//     virtual Iterator GetNext() const override {
//         return {};
//     }

//     virtual Iterator GetNth() const override {
//         return {};
//     }
// };
