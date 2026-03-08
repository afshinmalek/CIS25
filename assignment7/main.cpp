#include <algorithm> // I need this to use the sort() function!
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// I created this class to organize the data for each job.
class DataJob {
public:
  // I chose these 5 specific fields to analyze entry-level jobs by company
  // size.
  string jobTitle;
  int salaryUSD;
  string experienceLevel;
  string workSetting;
  string companyLocation;
  string companySize;

  // This function helps me display the job information neatly to the console.
  void displayJob() {
    cout << "- " << jobTitle << " (" << experienceLevel << ", " << workSetting
         << ")" << endl;
    cout << "  Company Location: " << companyLocation << " | Salary: $"
         << salaryUSD << endl;
    cout << "--------------------------------------------------------" << endl;
  }
};

// I need this helper function so the C++ sort() algorithm knows HOW to sort my
// objects. This tells it to put the job with the bigger salaryUSD first.
bool compareJobsBySalary(const DataJob &job1, const DataJob &job2) {
  return job1.salaryUSD > job2.salaryUSD;
}

int main() {
  // 1. Open the CSV file. It must be in the same folder as this code!
  ifstream file("jobs_in_data.csv");

  if (!file.is_open()) {
    cout << "Error: Could not open jobs_in_data.csv!" << endl;
    return 1;
  }

  // Instead of one list, I am making THREE vectors to group jobs by company
  // size!
  vector<DataJob> smallCompanyJobs;
  vector<DataJob> mediumCompanyJobs;
  vector<DataJob> largeCompanyJobs;

  string line;
  // Skipping the very first line because it just contains the column headers.
  getline(file, line);

  // Variables to hold the raw string data from the 12 columns in the CSV file.
  string workYear, jobTitle, jobCategory, salaryCurrency, salaryLocal;
  string salaryUSDStr, employeeResidence, experienceLevel;
  string employmentType, workSetting, companyLocation, companySize;

  // 2. Read through the dataset using getline to separate columns by commas.
  while (getline(file, workYear, ',')) {

    getline(file, jobTitle, ',');
    getline(file, jobCategory, ',');
    getline(file, salaryCurrency, ',');
    getline(file, salaryLocal, ',');
    getline(file, salaryUSDStr, ',');
    getline(file, employeeResidence, ',');
    getline(file, experienceLevel, ','); // This is the column I check first!
    getline(file, employmentType, ',');
    getline(file, workSetting, ',');
    getline(file, companyLocation, ',');
    getline(file,
            companySize); // The last column ends with a newline, not a comma.
    companySize = companySize[0];

    // 3. FIRST FILTER: I only want to look at Entry-level jobs.
    if (experienceLevel == "Entry-level") {

      // Create the job object and populate my 5 chosen fields.
      DataJob newJob;
      newJob.jobTitle = jobTitle;
      newJob.salaryUSD =
          stoi(salaryUSDStr); // Convert salary to integer for sorting
      newJob.experienceLevel = experienceLevel;
      newJob.workSetting = workSetting;
      newJob.companyLocation = companyLocation;
      newJob.companySize = companySize;

      // 4. SECOND FILTER: Route the entry-level job into the correct size
      // vector. I'm using companySize[0] just in case there are hidden spaces
      // or return characters (\r).
      if (companySize[0] == 'S') {
        smallCompanyJobs.push_back(newJob);
      } else if (companySize[0] == 'M') {
        mediumCompanyJobs.push_back(newJob);
      } else if (companySize[0] == 'L') {
        largeCompanyJobs.push_back(newJob);
      }
    }
  }

  file.close(); // Done reading the file!

  // 5. Sort all three vectors from highest salary to lowest!
  sort(smallCompanyJobs.begin(), smallCompanyJobs.end(), compareJobsBySalary);
  sort(mediumCompanyJobs.begin(), mediumCompanyJobs.end(), compareJobsBySalary);
  sort(largeCompanyJobs.begin(), largeCompanyJobs.end(), compareJobsBySalary);

  // 6. Print out the top 10 for each category!

  cout << "\n\n\n====================================================" << endl;
  cout << "  TOP 10 ENTRY-LEVEL DATA JOBS: SMALL COMPANIES (S)" << endl;
  cout << "====================================================\n" << endl;
  int smallDisplayCount =
      (smallCompanyJobs.size() < 10) ? smallCompanyJobs.size() : 10;
  for (int i = 0; i < smallDisplayCount; i++) {
    cout << "#" << (i + 1) << " ";
    smallCompanyJobs[i].displayJob();
  }

  cout << "\n\n\n====================================================" << endl;
  cout << "  TOP 10 ENTRY-LEVEL DATA JOBS: MEDIUM COMPANIES (M)" << endl;
  cout << "====================================================\n" << endl;
  int mediumDisplayCount =
      (mediumCompanyJobs.size() < 10) ? mediumCompanyJobs.size() : 10;
  for (int i = 0; i < mediumDisplayCount; i++) {
    cout << "#" << (i + 1) << " ";
    mediumCompanyJobs[i].displayJob();
  }

  cout << "\n\n\n====================================================" << endl;
  cout << "  TOP 10 ENTRY-LEVEL DATA JOBS: LARGE COMPANIES (L)" << endl;
  cout << "====================================================\n" << endl;
  int largeDisplayCount =
      (largeCompanyJobs.size() < 10) ? largeCompanyJobs.size() : 10;
  for (int i = 0; i < largeDisplayCount; i++) {
    cout << "#" << (i + 1) << " ";
    largeCompanyJobs[i].displayJob();
  }

  return 0;
}