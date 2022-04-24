struct Codec {
  urls: Vec<String>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
  fn new() -> Self {
    Self { urls: vec![] }
  }

  // Encodes a URL to a shortened URL.
  fn encode(&mut self, longURL: String) -> String {
    self.urls.push(longURL);
    (self.urls.len() - 1).to_string()
  }

  // Decodes a shortened URL to its original URL.
  fn decode(&self, shortURL: String) -> String {
    let n = shortURL.parse::<usize>().unwrap();
    self.urls[n].clone()
  }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let s: String = obj.encode(strs);
 * let ans: VecVec<String> = obj.decode(s);
 */