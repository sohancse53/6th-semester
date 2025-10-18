#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "int main() { float x; return 0; }";

    std::regex cppKeywords(R"(\b(alignas|alignof|and|and_eq|asm|auto|bitand|bitor|bool|break|case|catch|char|char16_t|char32_t|class|compl|const|constexpr|const_cast|continue|decltype|default|delete|do|double|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexcept|not|not_eq|nullptr|operator|or|or_eq|private|protected|public|register|reinterpret_cast|return|short|signed|sizeof|static|static_assert|static_cast|struct|switch|template|this|thread_local|throw|true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while|xor|xor_eq)\b)");

    std::smatch matches;
    std::string::const_iterator searchStart(text.cbegin());

    while (std::regex_search(searchStart, text.cend(), matches, cppKeywords)) {
        std::cout << "Found keyword: " << matches[0] << std::endl;
        searchStart = matches.suffix().first;
    }
}
