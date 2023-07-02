void httpSetRoutePathVar(HttpRoute *route, const char *key, const char *value)
{
    assert(route);
    assert(key);
    assert(value);

    GRADUATE_HASH(route, pathTokens);
    
    if (strchr(value, '$')) {
        value = stemplate(value, route->pathTokens);
    }
    
    mprAddKey(route->pathTokens, key, sclone(value));
}
