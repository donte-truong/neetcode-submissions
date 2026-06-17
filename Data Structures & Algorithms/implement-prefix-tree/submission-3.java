class TrieNode {
    public HashMap<String, TrieNode> children = new HashMap<String, TrieNode>();
    public boolean endOfWord = false;
}

class PrefixTree {

    public TrieNode root;

    public PrefixTree() {
        this.root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode curr = this.root;
        for (char c: word.toCharArray()) {
            String s = "" + c;
            if (!curr.children.containsKey(s)) {
                curr.children.put(s, new TrieNode());
            }
            curr = curr.children.get(s);
        }
        curr.endOfWord = true;
    }

    public boolean search(String word) {
        TrieNode curr = this.root;
        for (char c: word.toCharArray()) {
            String s = "" + c;
            if (!curr.children.containsKey(s)) {
                return false;
            }
            curr = curr.children.get(s);
        }
        return curr.endOfWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode curr = this.root;
        for (char c: prefix.toCharArray()) {
            String s = "" + c;
            if (!curr.children.containsKey(s)) {
                return false;
            }
            curr = curr.children.get(s);
        }
        return true;
    }
}
