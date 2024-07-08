#include <iostream>
#include <string>
using namespace std;
class Member
{
    int mid[1000];
    char name[1000][30];
    float height[1000];
    float weight[1000];
    float bmi[1000];
    int total = 0;

public:
    float calBMI(float h, float w)
    {
        return w / (h * h);
    }
    int check(int mi)
    {
        for (int i = 0; i < total; i++)
            if (mi == mid[i])
                return i;
        return -1;
    }
    void addMember()
    {
        int x, i;
        cout << endl;
        cout << "Enter new mid: ";
        cin >> x;
        i = check(x);
        if (i == -1)
        {

            mid[total] = x;
            cout << "Enter name(Name can't contain space): ";
            scanf(" %s", name[total]);
            cout << "Enter height: ";
            cin >> height[total];
            cout << "Enter weight: ";
            cin >> weight[total];
            bmi[total] = calBMI(height[total], weight[total]);
            total++;
        }
        else
        {
            cout << "Sorry for duplicate MID..." << endl;
        }
    }
    void bmiClass()
    {
        int x, i;
        cout << endl;
        cout << "Enter MID:";
        cin >> x;
        i = check(x);
        if (i != -1)
        {

            cout << "Name  : " << name[i] << endl;
            cout << "Height: " << height[i] << endl;
            cout << "Weight: " << weight[i] << endl;
            cout << "BMI   : " << bmi[i] << endl;
            cout << "BMI Class: " << endl;
            if (bmi[i] < 16)
                cout << "Severe Thinness" << endl;
            else if (bmi[i] <= 17)
                cout << "Moderate Thinness" << endl;
            else if (bmi[i] <= 18.5)
            {
                cout << "Mild Thinness" << endl;
            }
            else if (bmi[i] <= 25)
            {
                cout << "Normal" << endl;
            }
            else if (bmi[i] <= 30)
                cout << "Overweight" << endl;
            else if (bmi[i] <= 35)
                cout << "Obese Class I" << endl;
            else if (bmi[i] <= 40)
                cout << "Obese Class II" << endl;
            else
                cout << "Obese Class III" << endl;
        }
        else
            cout << "Member not found" << endl;
    }
    void maxHeightAndWeight()
    {
        cout << endl;
        if (total == 0)
        {
            cout << "Sorry No member is found." << endl;
            return;
        }
        int inxh;
        int inxw;
        float maxh = height[0];
        float maxw = weight[0];
        for (int i = 0; i < total; i++)
        {
            if (maxh < height[i])
            {
                maxh = height[i];
                inxh = i;
            }
            if (maxw < weight[i])
            {
                maxw = weight[i];
                inxw = i;
            }
        }
        cout << "Tall Member_" << endl;
        cout << "            Name   : " << name[inxh] << endl;
        cout << "            MID    : " << mid[inxh] << endl;
        cout << "            Height : " << height[inxh] << endl
             << endl;
        cout << "Fat  Member_" << endl;
        cout << "            Name   : " << name[inxw] << endl;
        cout << "            MID    : " << mid[inxw] << endl;
        cout << "            Weight : " << weight[inxw] << endl;
        cout << endl;
    }
    void minHeightAndWeight()
    {
        cout << endl;
        if (total == 0)
        {
            cout << "Sorry No member is found." << endl;
            return;
        }
        int inxh;
        int inxw;
        float minh = height[0];
        float minw = weight[0];
        for (int i = 0; i < total; i++)
        {
            if (minh > height[i])
            {
                minh = height[i];
                inxh = i;
            }
            if (minw > weight[i])
            {
                minw = weight[i];
                inxw = i;
            }
        }
        cout << "Small Member_" << endl;
        cout << "             Name   : " << name[inxh] << endl;
        cout << "             MID    : " << mid[inxh] << endl;
        cout << "             Height : " << height[inxh] << endl
             << endl;
        cout << "Thin Member_" << endl;
        cout << "             Name   : " << name[inxw] << endl;
        cout << "             MID    : " << mid[inxw] << endl;
        cout << "             Weight : " << weight[inxw] << endl;
        cout << endl;
    }
    void calAverageHeight()
    {
        cout << endl;
        if (total == 0)
        {
            cout << "There is no members." << endl;
            return;
        }
        float sumHeight = 0;
        for (int i = 0; i < total; i++)
            sumHeight += height[i];
        cout << "Average Height: " << sumHeight / total << endl;
    }
    void calAverageWeight()
    {
        cout << endl;
        if (total == 0)
        {

            cout << "There is no members." << endl;
            return;
        }
        float sumWeight = 0;
        for (int i = 0; i < total; i++)
            sumWeight += weight[i];
        cout << "Average Weight: " << sumWeight / total << endl;
    }
    void removeMember()
    {
        int id;
        cout << endl;
        cout << "Enter the ID of member: ";
        cin >> id;
        int found = check(id);
        if (found == -1)
        {
            cout << "There is no member of MID: " << id << endl;
            return;
        }
        for (int i = found; i < total - 1; i++)
        {
            mid[i] = mid[i + 1];
            strcpy(name[i], name[i + 1]);
            height[i] = height[i + 1];
            weight[i] = weight[i + 1];
            bmi[i] = bmi[i + 1];
        }
        total--;
    }
    void showMembers()
    {
        if (total == 0)
        {
            cout << "\nNo members found!" << endl;
            return;
        }
        printf("|-------------------------------------------------------------------------------|\n");
        printf("| IN  |           Name           |     MID     |  Height(m)| Weight(Kg)|  BMI   |\n");
        printf("|-------------------------------------------------------------------------------|\n");
        for (int i = 0; i < total; i++)
        {
            printf("| %-4d| %-25s| %-12d| %-10.2f| %-10.2f| %-7.2f|\n", i + 1, name[i], mid[i], height[i], weight[i], bmi[i]);
            printf("|-------------------------------------------------------------------------------|\n");
        }
    }
    void readFile()
    {
        FILE *inputFile;
        inputFile = fopen("input.txt", "r");
        fscanf(inputFile, "%d", &total);
        for (int i = 0; i < total; i++)
        {
            if (fscanf(inputFile, "%s %d %f %f %f", name[i], &mid[i], &height[i], &weight[i], &bmi[i]) == 5)
            {
                ;
            }
        }
        fclose(inputFile);
    }
    void writeFile()
    {
        FILE *outputFile;
        outputFile = fopen("input.txt", "w");
        if (total != 0)
            fprintf(outputFile, "%d\n", total);
        for (int i = 0; i < total; i++)
        {

            fprintf(outputFile, "%s %d %.2f %.2f %.2f\n", name[i], mid[i], height[i], weight[i], bmi[i]);
        }
        fclose(outputFile);
    }
    void update()
    {

        cout << endl;
        cout << "Enter MID: ";
        int id;
        cin >> id;
        int i = check(id);
        if (i == -1)
        {
            cout << endl
                 << "Memeber Not Found!" << endl;
            return;
        }
        //  cout << "Enter new MID: ";
        // cin >> mid[i];
        // cout << "Enter new Name: ";
        // cin >> name[i];
        cout << "Enter present Height: ";
        cin >> height[i];
        cout << "Enter present Weight: ";
        cin >> weight[i];
        bmi[i] = calBMI(height[i], weight[i]);
    }
    void deleteAll()
    {
        cout << endl;
        cout << "Do you want to delate all data? " << endl;
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        int option;
        cout << "       Enter option(1-2): ";
        cin >> option;
        if (option == 1)

        {
            cout << "Succesfully Deleted." << endl;
            total = 0;
            ;
        }
    }
    void showIndividual()
    {
        cout << endl;
        cout << "Enter MID: ";
        int mi;
        cin >> mi;
        int i = check(mi);
        if (i == -1)
        {
            cout << "Member not found!" << endl;
            return;
        }
        cout << endl;
        cout << "Name    : " << name[i] << endl;
        cout << "MID     : " << mid[i] << endl;
        cout << "Height  : " << height[i] << endl;
        cout << "weight  : " << weight[i] << endl;
        cout << "BMI     : " << bmi[i] << endl;
    }
};
void menu();
int main()
{
    Member m1;
    m1.readFile();
    while (1)
    {
        menu();
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            m1.addMember();
            break;
        case 2:
            m1.update();
            break;
        case 3:
            m1.removeMember();
            break;
        case 4:
            m1.maxHeightAndWeight();
            break;
        case 5:
            m1.minHeightAndWeight();
            break;
        case 6:
            m1.calAverageHeight();
            m1.calAverageWeight();
            break;
        case 7:
            m1.bmiClass();
            break;
        case 8:
            m1.showMembers();
            break;
        case 9:
            m1.showIndividual();
            break;
        case 10:
            m1.deleteAll();
            break;
        }
        if (option == 0)
            break;
    }
    m1.writeFile();
    return 0;
}
void menu()
{
    cout << endl
         << endl;
    cout << "******* Main *******" << endl
         << endl;
    cout << "1. Add Member" << endl;
    cout << "2. Update Member" << endl;
    cout << "3. Remove Member" << endl;
    cout << "4. Max Height & Weight" << endl;
    cout << "5. Min Height and Weight" << endl;
    cout << "6. Average Height and Weight" << endl;
    cout << "7. BMI Classification" << endl;
    cout << "8. Show Members' Data" << endl;
    cout << "9. Show Individual's Data " << endl;
    cout << "10. Delete All Data " << endl;
    cout << "0. Exit" << endl;
    cout << "\tEnter Your option(0-8): ";
}