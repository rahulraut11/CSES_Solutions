
    {
        while (b[j] < a[i] - k && (j < n))
            j++;
        if (b[j] < a[i] + k)
            ans++;
    }