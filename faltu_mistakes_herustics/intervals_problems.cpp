// your movie stuck at an interval again man...
// Ok, In most of the interval problems, you generally sort and try to find common elements in all the intervals
// it sometimes is useful in range based problems as well

// the best algo is Line Sweep which states
// you divide the intervals in pairs, start value gets a 1 {st,1}as pair and end gets a -1 {end+1,-1}.
// note: if the problem asks you to include the last interval, the end pair becomes end+1, to avoid overlap and value getting deducted before increment
// iterate count and find the maximum

// in future i might incude more stuff here as i encounter more such problems also,
// read it to know more:  https://leetcode.com/discuss/study-guide/2166045/line-sweep-algorithms
// basic code

int maximumBeauty(vector<int> &nums, int k)
{
    vector<pair<int, int>> intervals;

    for (auto &a : nums)
    {
        intervals.push_back({a - k, 1});
        intervals.push_back({a + k + 1, -1});
    }

    sort(intervals.begin(), intervals.end());

    int cnt = 0;
    int maxi = 0;

    for (auto &a : intervals)
    {
        cnt += a.second;
        maxi = max(cnt, maxi);
    }
    return maxi;
}
