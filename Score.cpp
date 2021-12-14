
#include "Score.h"

#include <fstream>

void Score::Save(const string &path, size_t score)
{
    ofstream file_stream(path);
    if (!file_stream.is_open())
        cerr << "failed to open or create: " << path << endl;
    file_stream << score;
}

size_t Score::Load(const string &path)
{
    string file_content;
    ifstream file_stream(path);
    if (!file_stream.is_open())
        return 0;
    getline(file_stream, file_content, '\0');
    try {
        return stoul(file_content);
    }
    catch (...) {
        return 0;
    }
}
