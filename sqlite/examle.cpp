void open_mem_db()
{
    char errcode = 0;
 
    void* pBuffer = NULL;
    HRSRC hr = ::FindResource(NULL, MAKEINTRESOURCE(IDR_ERRORCODEDB), RT_RCDATA);
 
    if (hr)
    {
        HGLOBAL hg = ::LoadResource(NULL, hr);
 
        if (hg)
        {
            DWORD dwSize = ::SizeofResource(NULL, hr);
            pBuffer = ::LockResource(hg);
 
            set_mem_db(pBuffer, dwSize);
 
            int nInitResult = readonlymemvfs_init();
            assert(nInitResult == SQLITE_OK);
            errcode = sqlite3_open_v2( "_", &s_database,
                SQLITE_OPEN_READONLY, READONLY_MEM_VFS_NAME );
        }
    }
}
