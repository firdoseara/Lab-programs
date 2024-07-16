import wikipedia
def search_and_return_info(query):
    try:
        wikipedia.set_lang("en")
        search_results=wikipedia.search(query)
        if not search_results:
            return "No results found. Please try another search term."
        page_summary=wikipedia.summary(search_results[0],sentences=2)
        page_url=wikipedia.page(search_results[0]).url
        return f"Here's what I found:\n{page_summary}\n\nYou can read more here:{page_url}"
    except wikipedia.exceptions.DisambiguationError as e:
        return f"Search term ambiguous.Did you mean:{','.join(e.options[:5])}?"
    except wikipedia.exceptions.PageError:
        return "No matching page found. Please try another search term."
search_term=input("Enter your search term: ")
result=search_and_return_info(search_term)
print(result)
