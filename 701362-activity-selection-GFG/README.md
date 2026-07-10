# [Activity Selection](https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1?_gl=1*7fj1rv*_up*MQ..*_gs*MQ..&gclid=Cj0KCQjwsMLSBhD9ARIsAIpUTDp3X8Sc0qkeFNts6xP1pnh02aS0gWM4i7p4Ywx_44-YcLuA0m5JLeQaAqCiEALw_wcB&gbraid=0AAAAAC9yBkCSpc1jrOts1NNC1yNQElHoR)
## Medium
Given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.
Note: Start time and finish time cannot overlap, i.e., if a person finishes an activity at time x, then they cannot start another activity at time x.
Examples:
Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]Output: 4Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}
Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]Output: 1Explanation: A person can perform at most one activity.
Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
Output: 3
Explanation: A person can perform activities 0, 1 and 3.
Constraints:1 ≤ start.size() = finish.size() ≤ 2*1050 ≤ start[i] ≤ finish[i] ≤ 109