<img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" align="right" height="65">

# Get Next Line
Esta es mi Libft

## Functions

<details>
<summary>

## **ft_rdlst**
</summary>

    Stores a set of strings in a list along with their length and line break location.
    The last string in the list always contains a newline and/or end of string.

</details>

<details>
<summary>

## **ft_lsttostr**
</summary>

    Transform a list into a string.
    This function is usefull because it makes easier to create a string from de line of the file.

</details>

<details>
<summary>

## **get_next_line**
</summary>

    **First read**
    1. Checks the file the BUFFER_SIZE are correct.
    2. Creates a list with the first line.
    3. Moves the list into a new string.
    4. Copies substring until newline or end of string to new string.
    5. Copies the remaining substring to the aux variable.
    6. Drops the full string.
    7. Returns the line.

    **Other read**
    1. Checks the file the BUFFER_SIZE are correct.
    2. Checks the aux var is not void
    4. Copies substring from aux to new string until newline or end of string.
    5. Copies the remaining substring to the aux variable.
    6. Checks the aux var is void and the new string is not ended with '\n'.
    6T.Reads next line and concatenate both 2 strings.
    6F.Returns the new string.

</details>