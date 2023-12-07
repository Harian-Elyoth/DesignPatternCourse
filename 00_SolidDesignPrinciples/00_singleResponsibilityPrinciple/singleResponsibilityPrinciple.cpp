#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

// Journal class represents a journal with a title and entries
struct Journal
{
  string title;
  vector<string> entries;

  // Constructor initializes the journal with a title
  explicit Journal(const string& title)
    : title{title}
  {
  }

  // Adds a new entry to the journal
  void add(const string& entry);

  // Saves the journal entries to a file
  void save(const string& filename);
};

// Adds a new entry to the journal
void Journal::add(const string& entry)
{
  static int count = 1;
  entries.push_back(boost::lexical_cast<string>(count++)
    + ": " + entry);
}

// Saves the journal entries to a file
void Journal::save(const string& filename)
{
  ofstream ofs(filename);
  for (auto& s : entries)
    ofs << s << endl;
}

// PersistenceManager class is responsible for handling the persistence of journal entries
struct PersistenceManager
{
  // Static method to save journal entries to a file
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int main()
{
  // Creating a Journal object
  Journal journal{"Dear Diary"};
  
  // Adding entries to the journal
  journal.add("I ate a bug");
  journal.add("I cried today");

  // Attempt to save the journal directly (commented out to demonstrate the use of PersistenceManager)
  // journal.save("diary.txt");

  // Creating a PersistenceManager object
  PersistenceManager pm;

  // Using PersistenceManager to save the journal entries to a file
  pm.save(journal, "diary.txt");

  return 0;
}
